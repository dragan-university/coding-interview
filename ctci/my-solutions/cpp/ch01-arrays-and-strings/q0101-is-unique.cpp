/*
Q 1.1

Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
---
Examples:

'dragan' -> false
'zoran' -> true

Questions to ask:
  What is max string size?
  can I modify the string, eg. sort it?
  what are the valid chars? only ascii? unicode?
  Can I use STL? (valid if I can use additionalk data structures)

Design:

if I can use STL classes (solution 1):
  use unordered set to hold the characters
  if char is already in the set return false

if I cannot use additional data structures (solution 2):
  sort the string
  check chars, if there are two same subsequent return false
*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
complexity is O(n) where n is string size and maximum value for n is number of
possible characters for exmaple if only ascii chars are valid, max value for n
is 255 (or 127 or possible less than that)
*/
bool has_all_unique_chars_v1(const string& s) {
    unordered_set<char> s_chars;

    for (auto c: s) {
        cout << "check " << c << endl;
        if (s_chars.find(c) != s_chars.end()) {
            cout << "already exist" << endl;
            return false;
        }

        s_chars.insert(c);
    }

    return true;
}

void test_v1(const string& s, bool expected) {
    string result = expected?"True":"False";
    cout << "v1 test: \"" << s << "\" should return " << result << endl;
    if (has_all_unique_chars_v1(s) == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }

    cout << endl;
}

void main()
{
    test_v1("dragan", false);
    test_v1("zoran", true);
}
