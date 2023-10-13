/*
https://www.hackerrank.com/challenges/icecream-parlor
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const bool DEBUG = false;

pair<int, int> find_flavors(int m, vector<int>& c) {
    for (int i=0; i<c.size()-1; i++) {
        if (c[i] > m) {
            continue;
        }

        for (int j=i+1; j<c.size(); j++) {
            if (DEBUG) cout << "check " << i << " and " << j << endl;
            if (c[i]+c[j] == m) {
                return make_pair(i+1, j+1);
            }
        }
    }

    return make_pair(-1, -1);
}

void test_find_flavors(int m, vector<int> &c, pair<int, int> &expected)
{
    cout << "test: " << m << " expected: " << expected.first << ":" << 
        expected.second << endl;
    cout << "costs: ";
    for (auto cost: c) {
        cout << cost << ":";
    }
    cout << endl;

    pair<int, int> actual = find_flavors(m, c);

    if (actual.first == expected.first && actual.second == expected.second) {
        cout << "PASS";
    } else {
        cout << "FAIL: E=" << expected.first << "," << expected.second << " A=" 
            << actual.first << "," << actual.second;
    }
    cout << endl;
}

void test_hr_sample1()
{
    vector<int> c = {1,4,5,3,2};

    pair<int, int> expected = {1, 4};
    test_find_flavors(4, c, expected);
}

void test_hr_sample2()
{
    vector<int> c = {2,2,4,3};

    pair<int, int> expected = {1, 2};
    test_find_flavors(4, c, expected);
}

void test_hr_tc01_1()
{
    vector<int> c = {5,75,25};

    pair<int, int> expected = {2, 3};
    test_find_flavors(100, c, expected);
}

void test_from_file(ifstream &infile, ifstream &outfile, int this_test, int test_to_run)
{
    pair<int, int> expected;
    outfile >> expected.first >> expected.second;

    int m;
    infile >> m;
    
    int n;
    infile >> n;

    vector<int> c(n);
    for (size_t i=0; i<n; ++i) {
        infile >> c[i];
    }

    if (test_to_run == -1 || this_test == test_to_run) {
        test_find_flavors(m, c, expected);
    }
}

void tests_from_files(const string &input, const string &output, int test_to_run=-1)
{
  ifstream infile(input);
  ifstream outfile(output);
  
  int t;
  infile >> t;
  cout << "t=" << t << endl;

  for (int i=0; i<t; i++) {
    test_from_file(infile, outfile, i, test_to_run);
  }
}

void hr_testcase() 
{
    int m;
    cin >> m;
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i=0; i<n; i++) {
        cin >> c[i];
    }

    pair<int, int> result = find_flavors(m, c);
    cout << result.first << " " << result.second << endl;
}

void hackerrank()
{
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        hr_testcase();
    }
}

int main() {
    //hackerrank();
    //test_hr_sample1();
    //test_hr_sample2();
    //test_hr_tc01_1();
    tests_from_files("input01.txt", "output01.txt", -1);
    return 0;
}
