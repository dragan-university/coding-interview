// morgan.cpp
//
// How to build:
// Linux: g++ --std=c++11 <file>.cpp
// Windows (vcvarsall.bat): cl /EHsc <file>.cpp

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cassert>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100000;
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

string find_min_string(char * A, char * B) {
  trace(__func__);
  clock_t begin = clock();
  int lenA = strlen(A);
  int lenB = strlen(B);
  int i = 0;
  int j = 0;
  char min_string[2*MAX_SIZE+3];
  char * pms = min_string;
  A[lenA] = 'z';
  A[lenA+1] = 0;
  B[lenB] = 'z';
  B[lenB+1] = 0;

  while ((i <= lenA) && (j <= lenB)) {
    //cout << "i=" << i << " j=" << j << endl;
    if (strcmp(A+i, B+j) < 0) {
      *pms = *(A+i);
      i++;
    } else {
      *pms = *(B+j);
      j++;
    }

    pms++;
  }

  min_string[lenA+lenB] = 0;
  cout << "profile: " << double(clock() - begin)/CLOCKS_PER_SEC << endl;
  return string(min_string);
}

void test_my_001(void)
{
  trace(__func__);
  char * A = "A";
  cout << "A=" << A << endl;
  char * B = "B";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AB", min_string);
}

void test_my_010(void)
{
  trace(__func__);
  char * A = "AZ";
  cout << "A=" << A << endl;
  char * B = "B";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("ABZ", min_string);
}

void test_my_020_hr_01(void)
{
  trace(__func__);
  char * A = "JACK";
  cout << "A=" << A << endl;
  char * B = "DANIEL";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("DAJACKNIEL", min_string);
}

void test_my_020_hr_02(void)
{
  trace(__func__);
  char * A = "ABACABA";
  cout << "A=" << A << endl;
  char * B = "ABACABA";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABACABA", min_string);
}

void test_my_030(void)
{
  trace(__func__);
  char * A = "ABACABA";
  cout << "A=" << A << endl;
  char * B = "ABACAB";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABACAB", min_string);
}

void test_my_031(void)
{
  trace(__func__);
  char * A = "ABACAB";
  cout << "A=" << A << endl;
  char * B = "ABACABA";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABACAB", min_string);
}

void test_my_032(void)
{
  trace(__func__);
  char * A = "ABACABW";
  cout << "A=" << A << endl;
  char * B = "ABACAB";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABW", min_string);
}

void test_my_033(void)
{
  trace(__func__);
  char * A = "ABACAB";
  cout << "A=" << A << endl;
  char * B = "ABACABW";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABW", min_string);
}

void test_my_034(void)
{
  trace(__func__);
  char * A = "ABACABC";
  cout << "A=" << A << endl;
  char * B = "ABACAB";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABC", min_string);
}

void test_my_035(void)
{
  trace(__func__);
  char * A = "ABACAB";
  cout << "A=" << A << endl;
  char * B = "ABACABC";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("AABABACABCABC", min_string);
}

void test_my_038(void)
{
  trace(__func__);
  char * A = "CA";
  cout << "A=" << A << endl;
  char * B = "CABD";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("CABCAD", min_string);
}

void test_my_039(void)
{
  trace(__func__);
  char * A = "CA";
  cout << "A=" << A << endl;
  char * B = "CACAA";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("CACAACA", min_string);
}

void test_my_040(void)
{
  trace(__func__);
  char * A = "BZD";
  cout << "A=" << A << endl;
  char * B = "QZE";
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
  char * A = "MNNM";
  cout << "A=" << A << endl;
  char * B = "NNM";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("MNNMNNM", min_string);
}

void test_my_044(void)
{
  trace(__func__);
  char * A = "OXOXXO";
  cout << "A=" << A << endl;
  char * B = "XOXXO";
  cout << "B=" << B << endl;

  string min_string = find_min_string(A, B);
  check_result("OXOXOXXOXXO", min_string);
}

void test_my_045(void)
{
  trace(__func__);
  //string A = "CABCABCAAACB";
  //string A = "CABCB";
  char A[MAX_SIZE] = "OXOOXO";
  cout << "A=" << A << endl;
  //string B = "CABCABCAAACB";
  //string B = "CABCB";
  char B[MAX_SIZE] = "XOOXO";
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

  string min_string = find_min_string((char*)A.c_str(), (char*)B.c_str());
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

  string min_string = find_min_string((char*)A.c_str(), (char*)B.c_str());
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
  char A[MAX_SIZE+1];
  char B[MAX_SIZE+1];

  scanf("%s", A);
  scanf("%s", B);

  string min_string = find_min_string(A, B);
  cout << min_string << endl;
}

void hackerrank()
{
  int T;
  scanf("%i\n", &T);

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
