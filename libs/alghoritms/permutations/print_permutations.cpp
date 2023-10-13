/* print_permutations.cpp
 *
 *  Created on: 2016-04-22
 *      Author: dragan
 *
 * How to build:
 * Linux: g++ -std=c++11 <file>.cpp
 * Windows: cl /EHsc <file>.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

void permutations_helper(const string &s, vector<char> &p)
{
    if (s.size() == 1) {
        for (char c: p) {
            cout << c;
        }

        cout << s << endl;
        return;
    }

    for (int i=0; i<s.size(); ++i) {
        p.push_back(s[i]);
        permutations_helper(s.substr(0, i) + s.substr(i+1), p);
        p.pop_back();
    }
}

/**
 * print all permutations of the given string
 */
void permutations(const string& s)
{
    vector<char> p;
    permutations_helper(s, p);
}

int main(void)
{
    permutations("123");
    permutations("abdf");
}
