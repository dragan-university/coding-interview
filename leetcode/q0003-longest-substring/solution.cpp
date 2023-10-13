/*
Build:

Linux & Mac:
    g++ <file.cpp> or 
    g++ --std=c++11 <file.cpp> 

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/
#include <cstddef>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int DEBUG_LEVEL = 10;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest_substring = 0;
        int current_substring = 0;
        unordered_set<char> letters;
        
        for (auto c: s) {
            if (DEBUG_LEVEL>5) {
                cout << "c:" << c << " -- max:" << longest_substring <<
                    " -- cur:" << current_substring << endl;
            }

            if (letters.count(c) > 0) {
                longest_substring = max(longest_substring, current_substring);
                current_substring = 1;
                letters.clear();
                letters.insert(c);
                continue;
            }

            current_substring++;
            letters.insert(c);
        }

        longest_substring = max(longest_substring, current_substring);
        return longest_substring;
    }
};

void test_solution(
        string s,
        int expected_result)
{
    cout << "s: " << s << ", expected: " << expected_result << endl;
    Solution sol;
    int actual_result = sol.lengthOfLongestSubstring(s);

    if (actual_result == expected_result) {
        cout << "PASS";
    } else {
        cout << "FAIL (actual=" << actual_result << ")";
    }
    cout << endl;
}

void test_sample_01()
{
    test_solution("abcabcbb", 3);
}

void test_submit_01()
{
    test_solution("dvdf", 3);
}

int main()
{
    //test_sample_01();
    test_submit_01();

    return 0;
}
