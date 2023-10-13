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

using namespace std;

const bool MYDEBUG = true;

enum Action {BREAK, CONTINUE, NONE};

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
      cout << actual[i];
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
  int i = 0;
  int j = 0;
  string min_string = "";
  string A = _A + 'z';
  string B = _B + 'z';

  while ((i < A.size()) && (j < B.size())) {
    if (A.substr(i) < B.substr(j)) {
      min_string += A[i];
      i++;
    } else {
      min_string += B[j];
      j++;
    }
  }

  return min_string.substr(0, min_string.size()-1);
}

string find_min_string_too_complex(const string& A, const string& B) {
  int i = 0;
  int j = 0;
  int m = A.size();
  int n = B.size();
  int nsc = 0;  // number of same chars
  string min_string = "";

  while (true) {
    if (MYDEBUG) {
      cout << "i=" << i << " j=" << j << " nsc=" << nsc << " s=" << min_string << endl;
    }

    if ((i == m) && (j == n)) {
      if (MYDEBUG) {
        cout << "no more A nor B" << endl;
      }

      min_string += (A.substr(i-nsc) + B.substr(j-nsc));
      break;
    }

    // did we reach end of string A?
    if (i == m) {
      if (MYDEBUG) {
        cout << "no more A" << endl;
      }

      // was there any number of same characers?
      if (nsc == 0) {
        if (MYDEBUG) {
          cout << "just add rest of B" << endl;
        }

        // no, just add the rest of string B and finish
        min_string += B.substr(j);
        break;
      }

      // there were some number of same chars
      if (MYDEBUG) {
        cout << "there were some number of same chars" << endl;
      }

      // check if current B is smaller then first same char
      if (B[j] < A[i-nsc]) {
        if (MYDEBUG) {
          cout << "B is smaller then first same character" << endl;
        }

        // add to min string part of B including current char, move A pointer back to the first
        // same cahr and reset number of same chars
        min_string += B.substr(j-nsc, nsc+1);
        i -= nsc;
        j++;
        nsc = 0;
        continue;
      }

      // check if current B is bigger then first same char
      if (B[j] > A[i-nsc]) {
        if (MYDEBUG) {
          cout << "B is bigger then first same character" << endl;
        }

        // add A then B and finish
        min_string += (A.substr(i-nsc) + B.substr(j-nsc));
        break;
      }

      // current B is same as first same char
      if (MYDEBUG) {
        cout << "current B is same as first same char" << endl;
      }

      // compare rest of B with the rest of same chars
      Action action = NONE;
      int insc = i-nsc;
      for (int k=1; k<nsc; k++) {
        if (j+k == n) {
          if (MYDEBUG) {
            cout << "no more Bs" << endl;
          }

          min_string += (A.substr(insc) + B.substr(j-nsc));
          action = BREAK;
          break;
        }

        if (B[j+k] < A[insc+k]) {
          min_string += B.substr(j-nsc, nsc+k+1);
          i -= nsc;
          j += (k+1);
          nsc = 0;
          action = CONTINUE;
          break;
        }

        if (B[j+k] > A[insc+k]) {
          min_string += (A.substr(insc) + B.substr(j-nsc));
          action = BREAK;
          break;
        }
      }

      if (action == BREAK) break;
      if (action == CONTINUE) continue;

      // rest of B was same as list of same chars

      // if we reached end of B just add rest of A and rest of B and finish
      if (j+nsc == n) {
        min_string += (A.substr(i-nsc) + B.substr(j-nsc));
        break;
      }

      // if next B is smaller than first same char add B than A and finish
      if (B[j+nsc+1] < A[insc]) {
        min_string += (B.substr(j-nsc) + A.substr(i-nsc));
        break;
      }

      // if next B is not smaller then first same char add A than B and finish
      min_string += (A.substr(i-nsc) + B.substr(j-nsc));
      break;
    }

    // did we reach end of string B?
    if (j == n) {
      if (MYDEBUG) {
        cout << "no more B" << endl;
      }

      // was there any number of same characers?
      if (nsc == 0) {
        if (MYDEBUG) {
          cout << "just add rest of A" << endl;
        }

        // no, just add the rest of string B and finish
        min_string += A.substr(i);
        break;
      }

      // there were some number of same chars
      if (MYDEBUG) {
        cout << "there were some number of same chars" << endl;
      }

      // check if current A is smaller then first same char
      if (A[i] < B[j-nsc]) {
        if (MYDEBUG) {
          cout << "A is smaller then first same character" << endl;
        }

        // add to min string part of A including current char, move B pointer back to the first
        // same cahr and reset number of same chars
        min_string += A.substr(i-nsc, nsc+1);
        i++;
        j -= nsc;
        nsc = 0;
        continue;
      }

      // check if current A is bigger than first same char
      if (A[i] > B[j-nsc]) {
        if (MYDEBUG) {
          cout << "A is bigger then first same character" << endl;
        }

        // add B then A and finish
        min_string += (B.substr(j-nsc) + A.substr(i-nsc));
        break;
      }

      // current A is same as first same char
      if (MYDEBUG) {
        cout << "current B is same as first same char" << endl;
      }

      // compare rest of A with the rest of same chars
      Action action = NONE;
      int jnsc = j-nsc;
      for (int k=1; k<nsc; k++) {
        if (i+k == m) {
          if (MYDEBUG) {
            cout << "no more As" << endl;
          }

          min_string += (B.substr(jnsc) + A.substr(i-nsc));
          action = BREAK;
          break;
        }

        if (A[i+k] < B[jnsc+k]) {
          min_string += A.substr(i-nsc, nsc+k+1);
          j -= nsc;
          i += (k+1);
          nsc = 0;
          action = CONTINUE;
          break;
        }

        if (A[i+k] > B[jnsc+k]) {
          min_string += (B.substr(jnsc) + A.substr(i-nsc));
          action = BREAK;
          break;
        }
      }

      if (action == BREAK) break;
      if (action == CONTINUE) continue;

      // rest of A was same as list of same chars

      // if we reached end of A just add rest of B and rest of A and finish
      if (i+nsc == m) {
        min_string += (B.substr(j-nsc) + A.substr(i-nsc));
        break;
      }

      // if next A is smaller than first same char add A than B and finish
      if (A[i+nsc+1] < B[jnsc]) {
        min_string += (A.substr(i-nsc) + B.substr(j-nsc));
        break;
      }

      // if next A is not smaller then first same char add B than A and finish
      min_string += (B.substr(j-nsc) + A.substr(i-nsc));
      break;
    }

    // we haven't reached end of any string yet

    // if current A is smaller then current B then add all same chars from A
    // and reset number of same chars and move B's index back to the first same char
    if (A[i] < B[j]) {
      min_string += A.substr(i-nsc, nsc+1);
      i++;
      j -= nsc;
      nsc=0;
      continue;
    }

    // if current A is bigger then current B do opposite from previous
    if (A[i] > B[j]) {
      min_string += B.substr(j-nsc, nsc+1);
      j++;
      i -= nsc;
      nsc=0;
      continue;
    }

    // A[i] == B[j]
    // TODO: refactor this - instead of comparing backward, compare forward
    if (nsc > 0) {

      /*
      int insc = i-nsc;
      for (int k=0; k<nsc; k++) {
        //

        if (A[i+k] > A[insc+k]) {

        }
      }
      */

      for (int l=0; l<nsc; l++) {
        if (A.substr(i-l, l+1) > A.substr(i-nsc, l+1)) {
          if (MYDEBUG) {
            cout << "nsc_substr=" << A.substr(i-nsc, l+1) << endl;
          }

          min_string += (A.substr(i-nsc, nsc-l) + B.substr(j-nsc, nsc-l));
          nsc = l;
          break;
        }

        if (A.substr(i-l, l+1) < A.substr(i-nsc, l+1)) {
          break;
        }
      }
    }


    nsc++;
    i++;
    j++;
  }

  return min_string;
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

  if (A.size() == B.size()) {
    return;
  }

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

const bool RUNALL = true;
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
  //test_my_047_from_file();
  //test_my_050_hr_17();
  hackerrank();
  return 0;
}
