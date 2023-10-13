/*
https://www.hackerrank.com/challenges/richie-rich

Design:
- First find how many pairs are palindrome different (e.g. d)
- then if k > d solution exists
  - we first chenge all non-palindromic pairs to the bigger value
  - then change (k-d)/2 pairs to 9

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <string>
#include <iostream>
using namespace std;

const bool DEBUG = true;

string make_largest_palindrome(const string &number, int k)
{
    string s = number;
    //long first_diff = -1;
    int required_changes = 0;
    bool is_digit_changed[s.size()/2];

    // just make number palindrom by making corresponding digits same to the bigger one
    for (size_t i=0; i<s.size()/2; ++i) {
        is_digit_changed[i] = false;

        if (s[i] != s[s.size()-i-1]) {
            is_digit_changed[i] = true;

            //cout << "i=" << i << endl;
            // if (first_diff == -1) {
            //     first_diff = i;
            // }

            if (required_changes < k) {
                if (s[i] > s[s.size()-i-1]) {
                    s[s.size()-i-1] = s[i];
                } else {
                    s[i] = s[s.size()-i-1];
                }

                required_changes++;
            } else {
                s = "-1";
                return s;
            }
        }
    }

    // if k is bigger then required to make palindrom, use the extra the incease 
    // some digits to 9, starting with most significant one
    size_t i = 0;
    while (k > required_changes && i < s.size()/2) {
        cout << "i=" << i << ", k=" << k << ", r=" << required_changes << endl;
        if (s[i] != '9') {
            if (is_digit_changed[i]) {
                s[i] = '9';
                s[s.size()-i-1] = '9';
                k--;
            } else if (k-1 > required_changes) {
                s[i] = '9';
                s[s.size()-i-1] = '9';
                k -= 2;
            }
        } 

        i++;
    }

    // what is this for?
    // if (k == 1 && first_diff != -1) {
    //     s[first_diff] = '9';
    //     s[s.size()-first_diff-1] = '9';
    //     k--;
    // }

    // if more changes can be made and number of digits is odd, make midle digit 9
    if (k > required_changes && s.size()%2 == 1) {
        s[s.size()/2] = '9';
    }

    return s;
}

void test_solution(const string &number, int k, const string &expected)
{
    cout << "number=" << number << ", k=" << k << ", expected=" << expected << endl;
    string actual = make_largest_palindrome(number, k);

    if (actual == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL (actual=" << actual << ")";
    }

    cout << endl;
}

void tc_hr_sample1()
{
    test_solution("3943", 1, "3993");
}

void tc_hr_sample2()
{
    test_solution("092282", 3, "992299");
}

void tc_hr_01()
{
    test_solution("0011", 1, "-1");
}

void tc_hr_02()
{
    test_solution("5", 1, "9");
}

void tc_hr_03()
{
    test_solution("932239", 2, "992299");
}

void tc_hr_05()
{
    test_solution("11331", 4, "99399");
}

void tc_my_01()
{
    test_solution("353", 1, "393");
}

void tc_my_02()
{
    test_solution("40922825", 5, "99922999");
}

void tc_my_03()
{
    test_solution("40922825", 3, "52922925");
}

void hackerrank()
{
    int n;
    int k;
    cin >> n >> k;

    string number;
    cin >> number;

    cout << make_largest_palindrome(number, k) << endl;
}

int main() {
    //hackerrank();
    tc_hr_sample1();
    tc_hr_sample2();
    tc_hr_01();
    tc_hr_02();
    tc_hr_03();
    tc_hr_05();
    tc_my_01();    
    tc_my_02();
    tc_my_03();

    return 0;
}
