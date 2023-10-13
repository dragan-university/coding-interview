/*
Q 1.9

Assume you have a method isSubstring which checks if one word is substring of 
another. Given two strings, s1 and s2, write code to check if s2 is a rotation 
of s1 using only one call to isSubstring (e.g. "waterbottle" is rotation of
"erbottlewat")
---
Examples:
"gandra" is rotation of "dragan"
"ganadra" is not rotation of "dragan"

Questions to ask:

Solution:
- If one string is rotation of the another then following properties are true:
  - strings have the same size
  - s1 is substring of s2s2 (and vice versa s2 is substring of s1s1)

  These two checks are enough to solve the problem.
*/
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
complexity depends on the implementation of the isSubstring function
*/
bool string_rotation(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }

    string s2s2 = s2+s2;

    if (s2s2.find(s1) == string::npos) {
        return false;
    } else {
        return true;
    }
}

void test_string_rotation(const string& a, const string& b, bool expected) {
    if (string_rotation(a, b) == expected) {
        cout << a << ":" << b << " PASS" << endl;
    } else {
        cout << a << ":" << b << " FAIL" << endl;
    }
}

int main()
{
    test_string_rotation("gandra", "dragan", true);
    test_string_rotation("gamdra", "dragan", false);
    return 0;
}
