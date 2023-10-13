/*
https://www.hackerrank.com/challenges/how-many-substrings

Analisys:
We can apply recursive algorithm. Let's s(n) be solution for string s with n
chars c1,...,cn. Then s(n) = s(n-1) + all unique strings that end with cn

Note: Only pass test cases 0 - 3; Test case 4 time out; test cases 5 -10
abort.

How to build:
Linux: g++ -std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

const int DEBUG_LEVEL = 10;

void how_many_substrings_r(string &s, unordered_set<string> &substrings)
{
    if (DEBUG_LEVEL > 5) {
        cout << "recursion: " << s << endl;
    }

    if (s.size() == 1) {
        substrings.insert(s);
        return;
    }

    // check string without the last char
    string _s = s.substr(0, s.size()-1);
    how_many_substrings_r(_s, substrings);

    // now check all substrings ending with last char
    for (size_t idx=0; idx<s.size(); ++idx) {
        if (substrings.count(s.substr(idx)) == 0) {
            substrings.insert(s.substr(idx));
        }
    }
}

size_t how_many_substrings(string &s, size_t left, size_t right)
{
    string ss = s.substr(left, right-left+1);
    if (DEBUG_LEVEL > 5) {
        cout << "INPUT: " << ss << endl;
    }

    unordered_set<string> substrings;
    how_many_substrings_r(ss, substrings);
    return substrings.size();
}

void test_solution(string &s, size_t left, size_t right, size_t expected_result)
{
    size_t actual_result = how_many_substrings(s, left, right);
    if (actual_result == expected_result) {
        cout << " PASS";
    } else {
        cout << " FAIL: E:" << expected_result << " A:" << actual_result;
    }
    cout << endl;
}

void test_hr_sample_1()
{
    string s("aabaa");
    test_solution(s, 1, 4, 8);
}

void test_hr_sample_2()
{
    string s("aabaa");
    test_solution(s, 0, 2, 5);
}

void hackerrank()
{
    int n;
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int a0 = 0; a0 < q; a0++){
        int left;
        int right;
        cin >> left >> right;
        cout << how_many_substrings(s, left, right) << endl;
    }
}

int main()
{
  //hackerrank();
  test_hr_sample_1();
  test_hr_sample_2();
  
  return 0;
}
