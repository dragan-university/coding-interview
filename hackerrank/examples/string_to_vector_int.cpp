// string_to_vector_int.cpp
//
// demonstrate how to convert a string containing list of integers into the
// vector of integers
//
// How to build:
// Linux: g++ -std-c++1 <file>.cpp
// Windows: cl /EHsc <file>.cpp
// Windows environment setup: run vcvarsall.bat

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void print_vector(const vector<int>& v) {
    for (auto item: v) {
        cout << item << " ";
    }

    cout << endl;
}

void string_to_vector_int(string &s, vector<int> &v)
{
    istringstream iss(s);

    while (iss) {
        int n;
        iss >> n;
        v.push_back(n);
    }

    // for some strange reason last number is duplicated, so we need to remove
    // duplicate !!!
    v.pop_back();
}

int main(void) {
    string s("3 4 2 7 8 11 -1 2");

    vector<int> v;

    string_to_vector_int(s, v);
    
    print_vector(v);

    return 0;
}
