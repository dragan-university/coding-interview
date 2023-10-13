// morgan.cpp
//
// How to build:
// Linux: g++ -std-c++1 <file>.cpp
// Windows: cl /EHsc <file>.cpp
// Windows environment setup: run vcvarsall.bat

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cassert>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

const bool MYDEBUG = true;

void trace(const string& message) {
  cout << "***** " << message << " *****" << endl;
}

void check_result(const string& expected, const string& actual)
{
  int m = expected.size();
  int n = actual.size();
  cout << "E:" << expected.substr(0,40) << endl;
  cout << "A:" << actual.substr(0, 40) << endl;

  int i = 0;
  while(true) {
    if ((i == m) || (i == n)) {
      break;
    }

    if (MYDEBUG) {
      if (i < 100) {
        cout << actual[i];
      }
    }

    if (expected[i] != actual[i]) {
      if (MYDEBUG) {
        cout << endl;
      }
      cout << "NOK: difference at: " << i << " (" << expected[i] << ":" << actual[i] << ")" << endl;
      cout << "E:" << expected.substr(i-5, 50) << endl;
      cout << "A:" << actual.substr(i-5, 50) << endl;
      return;
    }

    i++;
  }

  if (MYDEBUG) {
    cout << endl;
  }

  if (m == n) {
    cout << "OK :)))" << endl;
  } else {
    cout << "NOK - different size E:" << m << " A:" << n << endl;
  }
}

void print_char(char c)
{
  int i = c;

  cout << c << "=" << i << endl;
}

string find_min_string(const string& _A, const string& _B) {
  clock_t begin = clock();
  int i = 0;
  int j = 0;
  string min_string = "";
  string A = _A + 'z';
  string B = _B + 'z';

  while ((i < A.size()) && (j < B.size())) {
    //cout << "i=" << i << " j=" << j << endl;
    if (A.substr(i) < B.substr(j)) {
      min_string += A[i];
      i++;
    } else {
      min_string += B[j];
      j++;
    }
  }

  cout << "profile: " << double(clock() - begin)/CLOCKS_PER_SEC << endl;
  return min_string.substr(0, min_string.size()-1);
}

void test_my_001(void)
{
  string A = "A";
  cout << "A=" << A << endl;
  string B = "B";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AB", min_string);
}

void test_my_010(void)
{
  string A = "AZ";
  cout << "A=" << A << endl;
  string B = "B";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("ABZ", min_string);
}

void test_my_020_hr_01(void)
{
  string A = "JACK";
  cout << "A=" << A << endl;
  string B = "DANIEL";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("DAJACKNIEL", min_string);
}

void test_my_020_hr_02(void)
{
  string A = "ABACABA";
  cout << "A=" << A << endl;
  string B = "ABACABA";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABACABA", min_string);
}

void test_my_030(void)
{
  trace(__func__);
  string A = "ABACABA";
  cout << "A=" << A << endl;
  string B = "ABACAB";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABACAB", min_string);
}

void test_my_031(void)
{
  trace(__func__);
  string A = "ABACAB";
  cout << "A=" << A << endl;
  string B = "ABACABA";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABACAB", min_string);
}

void test_my_032(void)
{
  trace(__func__);
  string A = "ABACABW";
  cout << "A=" << A << endl;
  string B = "ABACAB";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABW", min_string);
}

void test_my_033(void)
{
  trace(__func__);
  string A = "ABACAB";
  cout << "A=" << A << endl;
  string B = "ABACABW";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABW", min_string);
}

void test_my_034(void)
{
  trace(__func__);
  string A = "ABACABC";
  cout << "A=" << A << endl;
  string B = "ABACAB";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABC", min_string);
}

void test_my_035(void)
{
  trace(__func__);
  string A = "ABACAB";
  cout << "A=" << A << endl;
  string B = "ABACABC";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABC", min_string);
}

void test_my_038(void)
{
  trace(__func__);
  string A = "CA";
  cout << "A=" << A << endl;
  string B = "CABD";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("CABCAD", min_string);
}

void test_my_039(void)
{
  trace(__func__);
  string A = "CA";
  cout << "A=" << A << endl;
  string B = "CACAA";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("CACAACA", min_string);
}

void test_my_040(void)
{
  trace(__func__);
  string A = "BZD";
  cout << "A=" << A << endl;
  string B = "QZE";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("BQZDZE", min_string);
}

// A: M N N M
// B:   N N M
// R: M N N M N N M
void test_my_042(void)
{
  trace(__func__);
  string A = "MNNM";
  cout << "A=" << A << endl;
  string B = "NNM";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("MNNMNNM", min_string);
}

void test_my_044(void)
{
  trace(__func__);
  string A = "OXOXXO";
  cout << "A=" << A << endl;
  string B = "XOXXO";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("OXOXOXXOXXO", min_string);
}

void test_my_045(void)
{
  trace(__func__);
  //string A = "CABCABCAAACB";
  //string A = "CABCB";
  string A = "OXOOXO";
  cout << "A=" << A << endl;
  //string B = "CABCABCAAACB";
  //string B = "CABCB";
  string B = "XOOXO";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  //check_result("CABCABCAAACABCABCAAACBCB", min_string);
  //check_result("CABCABCBCB", min_string);
  check_result("OXOOXOOXOXO", min_string);
}

void my_test_from_file(const string& infilename, const string& outfilename)
{
  ifstream infile(infilename);
  ifstream resultfile(outfilename);

  string A;
  string B;
  string expected_result;

  infile >> A >> B;
  resultfile >> expected_result;
  cout << "A.size=" << A.size() << endl;
  cout << "B.size=" << B.size() << endl;
  cout << "R.size=" << expected_result.size() << endl;
  cout << "R=" << expected_result.substr(0,40) << endl;

  string min_string = find_min_string(A, B);
  check_result(expected_result, min_string);
}

void test_my_046_from_file(void)
{
  trace(__func__);
  my_test_from_file("input46.txt", "output46.txt");
}

void test_my_047_from_file(void)
{
  trace(__func__);
  my_test_from_file("input47.txt", "output47.txt");
}

void hr_17_testcase(ifstream& infile, ifstream& resultfile)
{
  trace(__func__);
  string A;
  string B;
  string expected_result;

  infile >> A >> B;
  resultfile >> expected_result;
  cout << "A.size=" << A.size() << endl;
  cout << "B.size=" << B.size() << endl;
  cout << "R=" << expected_result.substr(0,40) << endl;

  string min_string = find_min_string(A, B);
  check_result(expected_result, min_string);
}

void test_my_050_hr_17()
{
  trace(__func__);
  ifstream infile("input17.txt");
  ifstream resultfile("output17.txt");

  int T;
  infile >> T;

  for(int i = 0; i < T; i++) {
    hr_17_testcase(infile, resultfile);
  }
}

void hr_testcase()
{
  string A;
  string B;

  cin >> A >> B;

  string min_string = find_min_string(A, B);
  cout << min_string << endl;
}

void hackerrank()
{
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    hr_testcase();
  }
}

const bool RUNALL = false;
int main()
{
  if (RUNALL) {
    test_my_001();
    test_my_010();
    test_my_020_hr_01();
    test_my_020_hr_02();
    test_my_030();
    test_my_031();
    test_my_032();
    test_my_033();
    test_my_034();
    test_my_035();
    test_my_038();
    test_my_039();
    test_my_040();
    test_my_042();
    test_my_044();
    test_my_045();
    test_my_046_from_file();
    test_my_047_from_file();
    test_my_050_hr_17();
  }
  //test_my_045();
  test_my_047_from_file();
  //test_my_050_hr_17();
  //hackerrank();
  return 0;
}
