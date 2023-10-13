/*
Q 1.4

Palindrome Permutation: Given a string, write a function to check if ti is a
permutation of a palindrome. A palindrome is a word or phrase that is the same
forwards and backwards. A permutation is a rearrangement of letters. The
palindrome does not need to be limited to just dictionary words.

---
Examples:

Input: Tact Coa
Output: True (permutations: "taco cat", "atco cta", etc)

---
Questions to ask:
- What is the max number of chars?
  If it is only ASCII we can have array to count chars
  If it is unicode perhaps we want to use a map or set

---
Design:
My Solution 1: a palindrom has following property:
- if string has even number of chars then each char appear even number
of times.
- if string has odd numbers of chars then one char appears odd number of times
and the rest even number
- space chars do not count

When we make permutation this property still holds true, and we can check that.

*/
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
complexity is O(?) ...
*/
bool is_palindrome_permutation(const string& s) {
    unordered_set<char> s_chars;

    for (char c: s) {
        if (isspace(c)) {
            continue;
        }
        
        auto it = s_chars.find(c);
        if (it == s_chars.end()) {
            s_chars.insert(c);
        } else {
            s_chars.erase(it);
        }
    }

    if ((s.size() % 2) == s_chars.size()) {
        return true;
    } else {
        return false;
    }
}

void test_is_palindrome_permutation(const string& s, bool expected) {
    if (is_palindrome_permutation(s) == expected) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}

int main()
{
    test_is_palindrome_permutation("tactcoa", true);
    test_is_palindrome_permutation("dragan", false);
    test_is_palindrome_permutation("d", true);
    test_is_palindrome_permutation("dr", false);
}
