/*
DP solution as explained by Tushar Roy
https://www.youtube.com/watch?v=_fgjrs570YE&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=10
--------------------------------------
coins: c[0],..., c[m-1]

S[i,j] - number of ways to make change on the amount 'j' with coins c[0],...,c[i-1]
S[0,j] = 0, j=0,1,2,...,n
S[i,0] = 1, i=0,1,2,...,m
S[i,j] = S[i-1,j], if c[i-1]>j
S[i,j] = S[i,j-c[i-1]] + S[i-1,j], if c[i-1]<=j

---
Recursive solution DID NOT PASS ALL TEST CASES - some test cases time-out

TC #2 that time-out
---------------------
Input:
166 23
5, 37, 8, 39, 33, 17, 22, 32, 13, 7, 10, 35, 40, 2, 43, 49, 46, 19, 41, 1, 12, 11, 28
Output:
96190959

---
DP solution

Failed tests 9, 10 and 14

How to build:
Linux: g++ -std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

const bool DEBUG = false;
const int DEBUG_LEVEL = 0;

void print_combination(vector<int> &combination)
{
    if (DEBUG_LEVEL > 5) {
        cout << "BINGO: ";
        for (auto c: combination) {
            cout << c << ":";
        }
        cout << endl;
    }
}

void print_counters(long long counter, int found)
{
    if (DEBUG_LEVEL > 2) {
        if (counter % 1000000 == 0) {
            cout << "COUNTER: " << counter << " FOUND: " << found << endl;
        }
    }
}

void coin_change(
        long long &counter,
        int target_amount,
        int current_amount,
        int left_coin_type_index,
        int number_of_coin_types,
        int coin_values[],
        int &change_count,
        vector<int> &change_combination) {

    if (left_coin_type_index == number_of_coin_types) return;

    for (
            int coin_type_index=left_coin_type_index;
            coin_type_index<number_of_coin_types;
            coin_type_index++) {
        counter++;
        print_counters(counter, change_count);
        change_combination.push_back(coin_values[coin_type_index]);
        int new_change = current_amount + coin_values[coin_type_index];
        if (DEBUG_LEVEL > 5) cout << counter << " ADD " << coin_values[coin_type_index] << " TOTAL: " << new_change << endl;
        if (new_change == target_amount) {
            change_count++;
            print_combination(change_combination);
        } else if (new_change < target_amount) {
            coin_change(
                counter,
                target_amount,
                new_change,
                coin_type_index,
                number_of_coin_types,
                coin_values,
                change_count,
                change_combination);
        } else {
            if (DEBUG_LEVEL > 5) cout << "OVER LIMIT " << new_change << endl;
        }

        change_combination.pop_back();
    }
}

// assumes that conins are in order
void coin_change_improved(
        long long &counter,
        int target_amount,
        int current_amount,
        int left_coin_type_index,
        int number_of_coin_types,
        int coin_values[],
        int &change_count,
        vector<int> &change_combination)
{

    if (left_coin_type_index == number_of_coin_types) return;

    for (
            int coin_type_index=left_coin_type_index;
            coin_type_index<number_of_coin_types;
            coin_type_index++) {
        counter++;
        print_counters(counter, change_count);
        change_combination.push_back(coin_values[coin_type_index]);
        int new_change = current_amount + coin_values[coin_type_index];
        if (DEBUG_LEVEL > 5) cout << "ADD " << coin_values[coin_type_index] << " TOTAL: " << new_change << endl;
        if (new_change == target_amount) {
            change_count++;
            print_combination(change_combination);
            change_combination.pop_back();
            return;
        } else if (new_change < target_amount) {
            coin_change_improved(
                counter,
                target_amount,
                new_change,
                coin_type_index,
                number_of_coin_types,
                coin_values,
                change_count,
                change_combination);
        } else {
            if (DEBUG_LEVEL > 5) cout << "OVER LIMIT " << new_change << endl;
            change_combination.pop_back();
            return;
        }

        change_combination.pop_back();
    }
}

void coin_change_improved_main(
        long long &counter,
        int target_amount,
        int current_amount,
        int left_coin_type_index,
        int number_of_coin_types,
        int coin_values[],
        int &change_count,
        vector<int> &change_combination)
{
    sort(coin_values, coin_values+number_of_coin_types);
    try {
        coin_change_improved(
            counter,
            target_amount,
            current_amount,
            left_coin_type_index,
            number_of_coin_types,
            coin_values,
            change_count,
            change_combination);
    } catch(exception &e) {
        cout << e.what() << endl;
    }
}

void print_dp_matrix(vector<vector<int> >& dp_matrix) {
    for (auto& v: dp_matrix) {
        for (auto c: v) {
            cout << c << ":";
        }
        cout << endl;
    }
    cout << endl;
}

// Tushan Roy's DP solution
size_t dp_coin_change(int amount, vector<int>& coins)
{
    vector<vector<size_t> > dp_matrix(coins.size());

    for (auto& v: dp_matrix) {
        v.push_back(1);
    }

    int value = 1;
    while (value<=amount) {
        if (value % coins[0]) {
            dp_matrix[0].push_back(0);
        } else {
            dp_matrix[0].push_back(1);
        }
        value++;
    }

    for (int ix=1; ix<coins.size(); ix++) {
        if (DEBUG) cout << "coin = " << coins[ix];
        for (int iy=1; iy<=amount; iy++) {
            if (DEBUG) cout << " amount:" << iy << ":";
            size_t count = dp_matrix[ix-1][iy];

            if (iy >= coins[ix]) {
                count += dp_matrix[ix][iy-coins[ix]];
            }

            if (DEBUG) cout << count << "-";
            dp_matrix[ix].push_back(count);
        }
        if (DEBUG) cout << endl;
    }

    //if (DEBUG) print_dp_matrix(dp_matrix);
    return dp_matrix[coins.size()-1][amount];
}

void test_coin_change(int amount, vector<int>& coins, size_t expected_result)
{
    size_t actual_result = dp_coin_change(amount, coins);
    if (actual_result == expected_result) {
        cout << " PASS";
    } else {
        cout << " FAIL: E:" << expected_result << " A:" << actual_result;
    }
    cout << endl;
}

void test_hr_sample()
{
    int amount = 4;
    vector<int> coins = {1,2,3};

    test_coin_change(amount, coins, 4);
}

void test_hr_02()
{
    int amount = 166;
    vector<int> coins = {5, 37, 8, 39, 33, 17, 22, 32, 13, 7, 10, 35, 40, 2, 43, 49, 46, 19, 41, 1, 12, 11, 28};

    test_coin_change(amount, coins, 96190959);
}

void test_hr_09()
{
    int amount = 250;
    //int amount = 4;
    vector<int> coins = {41, 34, 46, 9, 37, 32, 42, 21, 7, 13, 1, 24, 3, 43, 2, 23, 8, 45, 19, 30, 29, 18, 35, 11};

    test_coin_change(amount, coins, 15685693751);
    //test_coin_change(amount, coins, 4);
}

void hackerrank()
{
    int N;
    int M;

    cin >> N;
    cin >> M;

    vector<int> C(M);

    for (int i=0; i<M; i++) {
        cin >> C[i];
    }

    size_t result = dp_coin_change(N, C);
    cout << result << endl;
}

int main()
{
  //hackerrank();
  //test_hr_sample();
  //test_hr_02();
  test_hr_09();
  
  return 0;
}
