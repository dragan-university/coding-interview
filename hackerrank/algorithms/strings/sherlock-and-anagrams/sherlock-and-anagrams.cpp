// sherlock-and-anagrams.cpp
//
// Implememented two solutions slow and fast.
// Slow is 'brute force' type solution but it works.
// Fast does not find all.
// To make find all, it maybe become slow.
// So it maybe that 'brute force' is right way.
//
// How to build:
// Linux: g++ -std=c++11 <file>.cpp
// Windows: cl /EHsc <file>.cpp

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

string anagram_pair_to_string(
    size_t a1,
    size_t a2,
    size_t b1,
    size_t b2
)
{
    return to_string(a1)+":"+to_string(a2)+"-"+to_string(b1)+":"+to_string(b2);
}

void print_collection(const vector<int>& col)
{
    for (auto item: col) {
        cout << item << ":";
    }
    cout << endl;
}

#include "find_pairs_fast.h"
#include "find_pairs_slow.h"

void perform_test(const string& s, size_t expected_result)
{
    cout << "=== " << s << " ===" << endl;
    
    cout << "fast" << endl;
    size_t actual_result = find_anagrammatic_pairs(s);
    
    if (actual_result == expected_result) {
        cout << "OK: " << actual_result << " pairs" << endl;
    } else {
        cout << "NOK: expected " << expected_result << ", actual " << actual_result << endl;
    }   

    cout << "slow" << endl;
    actual_result = find_anagrammatic_pairs_slow(s);
    
    if (actual_result == expected_result) {
        cout << "OK: " << actual_result << " pairs" << endl;
    } else {
        cout << "NOK: expected " << expected_result << ", actual " << actual_result << endl;
    }   
}

void test_010_hr00_1(void)
{
  perform_test("abba", 4);
}

void test_010_hr00_2(void)
{
  perform_test("abcd", 0);
}

void test_010_hr01_1(void)
{
  perform_test("ifailuhkqq", 3);
}

void test_010_hr01_4(void)
{
  string A = "pvmupwjjjf";
  perform_test(A, 6);
}

void test_010_hr02_1(void)
{
  string A = "ifailuhkqqhucpoltgtyovarjsnrbfpvmupwjjjfiwwhrlkpekxxnebfrwibylcvkfealgonjkzwlyfhhkefuvgndgdnbelgruel";
  perform_test(A, 399);
}

void test_020(void)
{
  string A = "drarad";
  /*
  0,0 - 5,5
  0,2 - 3,5
  0,4 - 1,5
  1,1 - 3,3
  1,2 - 2,3
  1,2 - 3,4
  2,2 - 4,4
  2,3 - 3,4
  */
  perform_test(A, 8);
}

void test_030(void)
{
  string A = "dtraxratd";
  /*
01  0,0 - 8,8 d
02  0,1 - 7,8 dt td
03  0,3 - 5,8 dtra ratd
04  0,4 - 4,8 dtrax xratd
05  0,6 - 2,8 dtraxra raxratd
06  0,7 - 1,8 dtraxrat traxratd
07  1,1 - 7,7 t
08  1,3 - 5,7 tra rat
09  1,4 - 4,7 trax xrat
10  1,6 - 2,7 traxra raxrat
11  2,2 - 5,5 r
12  2,4 - 3,5 rax axr
13  3,3 - 6,6 a
14  3,5 - 4,6 axr xra
15  2,3 - 5,6 ra ra
  */
  perform_test(A, 15);
}

void test_040(void)
{
  string A = "dtdt";
  perform_test(A, 5);
}

void test_050(void)
{
  string A = "bacxyabc";
  /*
  0,0 - 6,6
  0,1 - 5,6
  0,4 - 2,6
  0,5 - 1,6
  1,1 - 5,5
  1,4 - 2,5
  2,2 - 7,7
  2,6 - 3,7
  0,2 - 5,7
  */
  perform_test(A, 9);
}

void hr_testcase()
{
  string A;

  cin >> A;

  cout << find_anagrammatic_pairs(A) << endl;
}

void hackerrank()
{
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    hr_testcase();
  }
}

#define HACKERRANK
int main()
{
  #ifdef HACKERRANK
  //hackerrank();
  //test_010_hr00_1();
  //test_010_hr02_1();
  test_050();
  #else
  test_010_hr00_1();
  test_010_hr00_2();
  test_010_hr01_1();
  test_010_hr01_4();
  test_010_hr02_1();
  test_020();
  test_030();
  test_040();
  test_050();
  #endif

  return 0;
}
