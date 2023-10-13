/*
Q 1.5 One Away

Thee are three types of edits that can be performed on string: insert a 
character, remove a character, or replace a character. Given two strings, write 
a function to check if they are max one edit away.

---
Examples:

pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bae -> false
pale, pel -> false

Questions to ask:

Solution:
- if strings size diff for more then 2 they are not one away
- if strings are of the same size then only valid operation is 'replacing a char'
  in this case we simply iterate through the strings' chars and when we find 
  diff (if any), we make them same. If there is no more diffs they are one edit away,
  otherwise they are not
- if strings sizes differ by one then valid operations a insert or remove a char.
  in this case, we again iterate until we reach first diff. If we reach it, we skip
  that char in the longer string and continue checking. If there are no more diffs
  then they are one away. Otherwise, not. If there is no diff at all they are also a
  one away

  
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*
return true if strings are one away, otherwise false
complexity is O(n) where n is shorter string lenght
*/
bool one_away(const string& a, const string& b) {
    if (abs((int)(a.size() - b.size())) > 1) {
        return false;
    }

    string x(a);
    string y(b);

    if (a.size() > b.size()) {
        x = b;
        y = a;
    }

    size_t i = 0;
    size_t d = 0;
    while (i<x.size()) {
        if (x[i] != y[i+d]) {
            d++;

            if (d == 2) {
                return false;
            }
        }

        i++;
    }

    return true;
}


void test_one_away(const string& a, const string& b, bool expected) {
    if (one_away(a, b) == expected) {
        cout << a << ":" << b << " PASS" << endl;
    } else {
        cout << a << ":" << b << " FAIL" << endl;
    }
}

int main()
{
    test_one_away("dragan", "drgan", true);
    test_one_away("pale", "bae", false);
    return 0;
}
