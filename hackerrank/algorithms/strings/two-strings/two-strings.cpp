// two-strings.cpp
//
// How to build: 
// Linux: g++ -std=c++11 <file>.cpp
// Windows: cl /EHsc <file>.cpp

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

// Find if there is a substring that appears in both A and B
// print YES or NO
void find_substring(const string& A, const string& B) 
{
    string::size_type found = B.find_first_of(A);
    
    if (found != string::npos) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

void test_010_hr(void)
{
  string A = "hello";
  string B = "world";

  find_substring(A, B);
}

void test_020_hr(void)
{
  string A = "hi";
  string B = "world";

  find_substring(A, B);
}

void hr_testcase()
{
  string A;
  string B;

  cin >> A >> B;
  
  find_substring(A, B);
}

void hackerrank()
{
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    hr_testcase();
  }
}

#define RUNTESTS
int main()
{
  #ifdef RUNTESTS
    test_010_hr();
    test_020_hr();
  #else
    hackerrank();
  #endif

  return 0;
}
