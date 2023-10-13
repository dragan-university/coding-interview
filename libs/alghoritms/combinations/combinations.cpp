/* combinations.cpp

Created on: 2017-02-20
Author: dragan

How to build:
Linux: g++ -std=c++11 <file>.cpp
Windows (vcvarsall): cl /EHsc <file>.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

const bool DEBUG = false;

void combinations_r(const string &s, size_t n, string &c)
{
    if (DEBUG) cout << s << ":" << n << ":" << c << endl;
    if (n == 0) {
        cout << c << endl;
        return;
    }

    for (size_t i=0; i<s.size(); ++i) {
        c.push_back(s[i]);
        combinations_r(s.substr(i+1), n-1, c);
        c.pop_back();
    }
}

// prints all combinations of size n of the letters of string s
void combinations(const string& s, size_t n)
{
    string c = "";
    combinations_r(s, n, c);
}

int main(void)
{
    combinations("12345", 3);
}
