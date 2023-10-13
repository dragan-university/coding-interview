/*
Q 1.6

Implement a method to perform basic string compression using the counts of
repeated characters. For example, the string aabcccccaaa would become
a2b1c5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.

---
Examples:

Questions to ask:

Design:
Let's assume we only have small letters
- start with 1st char and intialize counter to 1
- for each char in string
  - if char is same as previous increase counter and continue
  - else print prev char * count, set new char and counter to 1


*/
#include <iostream>
#include <string>

using namespace std;

/*
complexity is O(?) ...
*/
void compress_string(string& s) {
    string cs("");
    char c = s[0];
    int counter = 1;
    for (int i=1; i<s.size(); i++) {
        if (s[i] == c) {
            counter++;
            //cout << c << ":" << counter << endl;
        } else {
            cs += (c + to_string(counter));
            c = s[i];
            counter = 1;
            //cout << cs << endl;
        }
    }

    cs += (c + to_string(counter));

    if (cs.size() < s.size()) {
        s = cs;
    }
}

void test_compress_string(const string& s, const string& expected) {
    string cs(s);
    compress_string(cs);

    if (cs == expected) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL (" << cs << ")" << endl; 
    }
}

int main()
{
    test_compress_string("dddddrragggaaann", "d5r2a1g3a3n2");
    test_compress_string("aaaaabbb", "a5b3");
    test_compress_string("abbab", "abbab");
    return 0;
}
