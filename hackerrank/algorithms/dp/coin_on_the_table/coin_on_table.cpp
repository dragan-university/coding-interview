/*
Coin on the table
https://www.hackerrank.com/challenges/coin-on-the-table

------------
Solution:

I implemented recursive brute force type solution. Examine all possible paths
from (0,0) to '*', and take minimum that can be done in the given time.

Possible improvement:



------------
Results:

2017-02-19
PASS: TC 0, 1, 10
FAIL: TC 2 - 9
------------
Test cases from HR

TC 02 (failed due to timeout)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Input:
20 17 47
DRLULLRRRLRDLRRLU
URUURLRLLLDULRRRR
DRDLDDLDRRDRURRLR
DRRRRRRLDULDDUDLD
DULRDDULDUDULRDUD
LRURUDURRUURDDUDL
URURDLRUULRRDLDLR
DLRUDLDRUUDULUDUU
*ULLURDRDUURLDRDR
ULDUDUUULLURURURR
LDRDLDRRLDDRRLRLD
RDDLURRRDDLRDURLD
ULRLRLRRLLLRRURRL
RLLLDRDURLRURLUDD
DRLDURRLURUULLRDU
RURRUDLLLDDDRUUUD
UUUUDDLRURULRRDRD
URDUUDRDLDRLLULRU
DRDUUULUUDURULDDL
LLULDRLRRRUDLDRRU

Output:
3

-----------------
HR Solutions

Getting wrong answer for TestCase#6, got corrected for all others...
Could somebody tell - what coudld have gone wrong:

import java.io.; import java.util.;
public class Solution {
    private static int n = 0;
    private static int m = 0;

    private static int dp[][][];

    static int min(int a, int b) {
        return a < b ? a : b;
    }

    static int selectMax(int a, int l) {
        return a == Integer.MAX_VALUE ? Integer.MAX_VALUE : a + l;
    }

    static int func(char arr[][], int x, int y, int k) {
        if(x < 0 || x >= n || y < 0 || y >= m)
            return Integer.MAX_VALUE;

        if(arr[x][y] == '*') {
            //System.out.println("res found" + " x:" + x + " y:" + y + " k: " + k);
            return 0;
        }

        if(k == 0)
            return Integer.MAX_VALUE;

        if(dp[x][y][k-1] != -1)
            return dp[x][y][k-1];

        int minRes = Integer.MAX_VALUE;
        minRes = min(minRes, selectMax(func(arr, x,y+1, k-1), arr[x][y] == 'R' ? 0 : 1));
        minRes = min(minRes, selectMax(func(arr, x+1,y, k-1), arr[x][y] == 'D' ? 0 : 1));
        minRes = min(minRes, selectMax(func(arr, x,y-1, k-1), arr[x][y] == 'L' ? 0 : 1));
        minRes = min(minRes, selectMax(func(arr, x-1,y, k-1), arr[x][y] == 'D' ? 0 : 1));

        dp[x][y][k-1] = minRes;
        return dp[x][y][k-1];
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        n = s.nextInt();
        m = s.nextInt();
        int k = s.nextInt();

        dp = new int[n][m][k];
        char arr[][] = new char[n][m];

        s.nextLine();
        for(int i=0; i<n; ++i) {
            arr[i] = s.nextLine().toCharArray();
            for(int j=0; j<m; ++j) {
                for(int p=0; p<k; ++p)
                    dp[i][j][p] = -1;
            }
        }

        int res = func(arr, 0, 0, k);
        System.out.println(res == Integer.MAX_VALUE ? -1 : res);
    }
}
-----------------
Build:
Linux: g++ -std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

const int DEBUG = false;

void print_map_iv(const string &s, const map<int, vector<int> > &m)
{
    cout << s << "=";
    for (auto &e: m) {
        cout << e.first << "-";
        for (auto &i: e.second) {
            cout << i << ":";
        }
        cout << "***";
    }
    cout << endl;
}

void print_vector_i(const vector<int> &v) {
    cout << "v=";
    for (auto e: v) {
        cout << e << ":";
    }
    cout << endl;
}

// My solution
void coin_on_table(
        vector<vector<char> > &table,
        int t, // max allowed time (i.e. number of moves)
        size_t h,  // height
        size_t w,  // width
        size_t row,
        size_t col,
        string &path,
        unsigned &current_counter,
        unsigned &min_counter)
{
    if (DEBUG) cout << "a[" << row << "," << col << "]=" << table[row][col] << endl;
    if (DEBUG) this_thread::sleep_for(chrono::milliseconds(100));

    if (table[row][col] == '*') {
        // the target is reached
        if (path.size() <= t) {
            if (current_counter < min_counter) {
                min_counter = current_counter;
            }

            if (DEBUG) cout << "current=" << current_counter << " min=" << min_counter << endl;
            if (DEBUG) cout << "path=" << path << endl;
        }
        return;
    }

    if (table[row][col] == 'x') {
        // this filed was already visited
        return;
    }

    // save the current field
    char c = table[row][col];
    table[row][col] = 'x';

    if (row < h-1) {
        // we can move down
        path += "D";
        if (c == 'D') {
            coin_on_table(table, t, h, w, row+1, col, path, current_counter, min_counter);
        } else {
            current_counter++;
            coin_on_table(table, t, h, w, row+1, col, path, current_counter, min_counter);
            current_counter--;
        }
        path = path.substr(0, path.size()-1);
    }

    if (row > 0) {
        // we can move up
        path += "U";
        if (c == 'U') {
            coin_on_table(table, t, h, w, row-1, col, path, current_counter, min_counter);
        } else {
            current_counter++;
            coin_on_table(table, t, h, w, row-1, col, path, current_counter, min_counter);
            current_counter--;
        }
        path = path.substr(0, path.size()-1);
    }

    if (col < w-1) {
        // we can move right
        path += "R";
        if (c == 'R') {
            coin_on_table(table, t, h, w, row, col+1, path, current_counter, min_counter);
        } else {
            current_counter++;
            coin_on_table(table, t, h, w, row, col+1, path, current_counter, min_counter);
            current_counter--;
        }
        path = path.substr(0, path.size()-1);
    }

    if (col > 0) {
        // we can move left
        path += "L";
        if (c == 'L') {
            coin_on_table(table, t, h, w, row, col-1, path, current_counter, min_counter);
        } else {
            current_counter++;
            coin_on_table(table, t, h, w, row, col-1, path, current_counter, min_counter);
            current_counter--;
        }
        path = path.substr(0, path.size()-1);
    }

    // restore current fieled value
    table[row][col] = c;
}

void test_coin_on_table(
        vector<vector<char> > &table,
        int t,
        unsigned expected_result)
{
    size_t h = table.size();
    size_t w = table[0].size();
    unsigned current_counter = 0;
    unsigned actual_result = h*w;
    string path = "";

    cout << "my solution" << endl;
    clock_t tstart = clock();
    coin_on_table(table, t, h, w, 0, 0, path, current_counter, actual_result);
    cout << "Time taken: " << (double)((clock() - tstart)/CLOCKS_PER_SEC) << endl;

    cout << "E:" << expected_result << " A:" << actual_result;
    if (actual_result == expected_result) {
        cout << " PASS";
    } else {
        cout << " FAIL";
    }
    cout << endl;
}

void hackerrank()
{
    int N, M, K;

    cin >> N;
    cin >> M;
    cin >> K;

    vector<vector<char> > table(N);

    for (int row=0; row<N; ++row) {
        string srow;
        cin >> srow;
        for (int col=0; col<M; ++col) {
            table[row].push_back(srow[col]);
        }
    }

    string path = "";
    unsigned current_counter = 0;
    unsigned result = M*N;
    coin_on_table(table, K, N, M, 0, 0, path, current_counter, result);
    cout << result << endl;
}

void test_hr_sample_01()
{
    vector<vector<char> > table = {
        {'R', 'D'},
        {'*', 'L'}
    };

    test_coin_on_table(table, 1, 1);
}

void test_hr_sample_02()
{
    vector<vector<char> > table = {
        {'R', 'D'},
        {'*', 'L'}
    };

    test_coin_on_table(table, 3, 0);
}

void test_my_01()
{
    vector<vector<char> > table = {
        {'R', 'D', 'D'},
        {'*', 'R', 'L'},
        {'U', 'R', 'U'}
    };

    test_coin_on_table(table, 1, 1);
}

void test_my_02()
{
    vector<vector<char> > table = {
        {'R', 'D', 'D'},
        {'*', 'R', 'D'},
        {'U', 'L', 'L'}
    };

    test_coin_on_table(table, 1, 1);
}

void test_my_03()
{
    vector<vector<char> > table = {
        {'R', 'D', 'D'},
        {'*', 'R', 'D'},
        {'U', 'L', 'L'}
    };

    test_coin_on_table(table, 7, 0);
}

int main()
{
  //hackerrank();
  test_hr_sample_01();
  test_hr_sample_02();
  test_my_01();
  test_my_02();
  test_my_03();
  return 0;
}
