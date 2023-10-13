// sherlock-and-valid-string.cpp
//
// Solution overview:
// - create map containing frequency of all chars
// - map must satisfy following properties to be able to create valid string
//   with a max single removal:
//   - all frequencies must be same or 
//   - max one frequency is grether for one then the rest
//
// How to build:
// Linux: g++ -std=c++11 <file>.cpp
// Windows: cl /EHsc <file>.cpp

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<char, int> calculate_chars_frequency(const string& s) {
    //cout << "=== calculate_chars_frequency ===" << endl;
    unordered_map<char, int> chars_frequency;
    
    for (char c: s) {
        //cout << "c=" << c << endl;
        if (chars_frequency.count(c) == 0) {
            //cout << "new";
            chars_frequency[c] = 1;
        } else {
            //cout << "increment";
            chars_frequency[c]++;
        }
        //cout << endl;
    }
    
    return chars_frequency;
}

unordered_map<int, int> calculate_frequencies_counter(
        const unordered_map<char, int>& chars_frequency) {
    //cout << "=== calculate_frequencies_counter ===" << endl;
    unordered_map<int, int> frequencies_counter;
    
    for (auto& x: chars_frequency) {
        //cout << "cf: " << x.first << ":" << x.second << endl;
        if (frequencies_counter.count(x.second) == 0) {
            //cout << "new";
            frequencies_counter[x.second] = 1;
        } else {
            //cout << "increment";
            frequencies_counter[x.second]++;
        }
        //cout << endl;
    }
    
    return frequencies_counter;
}

bool check_frequencies_counters(const pair<int, int>& A, const pair<int, int>& B) {
    //cout << "=== check_frequencies_counters ===" << endl;
    //cout << "A: " << A.first << ":" << A.second << endl;
    //cout << "B: " << B.first << ":" << B.second << endl;
    bool result = true;
    
    if ((A.second > 1) && (B.second > 1)) {
        result = false;
    } else if (A.second == 1) {
        if ((A.first != 1) && ((A.first - B.first) != 1)) {
            result = false;
        }
    } else if (B.second == 1) {
        if ((B.first != 1) && ((B.first - A.first) != 1)) {
            result = false;
        }
    }
    
    return result;
}

string is_string_valid(const string& s)
{
    //cout << "=== is_string_valid ===" << endl;
    unordered_map<char, int> chars_frequency = calculate_chars_frequency(s);
    unordered_map<int, int> frequencies_counter = 
            calculate_frequencies_counter(chars_frequency);
    
    string result = "NO";
    
    if (frequencies_counter.size() == 1) {
        //cout << "only one frequency" << endl;
        result = "YES";
    } else if (frequencies_counter.size() == 2) {
        //cout << "two frequencies" << endl;
        auto it = frequencies_counter.begin();
        auto A = *it;
        it++;
        auto B = *it;
        
        if (check_frequencies_counters(A, B)) {
            result = "YES";
        }
    } else {
        //cout << "more then 2 frequencies" << endl;
    }
    
    return result;
}

void perform_test(const string& s, const string& expected_result)
{
    cout << "=== " << s << " ===" << endl;
    
    string actual_result = is_string_valid(s);
    
    if (actual_result == expected_result) {
        cout << "OK: " << actual_result << endl;
    } else {
        cout << "NOK: expected " << expected_result << ", actual " << actual_result << endl;
    }   
}

void test_010_hr00_1()
{
    perform_test("aabbcd", "NO");
}

void test_020()
{
    perform_test("aabbbacc", "NO");
}

void test_030()
{
    perform_test("abbac", "YES");
}

void hackerrank()
{
    string A;
    cin >> A;

    cout << is_string_valid(A) << endl;
}

//#define HACKERRANK
int main()
{
    #ifdef HACKERRANK
    hackerrank();
    #else
    test_010_hr00_1();
    test_020();
    test_030();
    #endif

    return 0;
}
