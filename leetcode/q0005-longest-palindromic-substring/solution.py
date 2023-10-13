"""
5 - https://leetcode.com/problems/longest-palindromic-substring/description/

Given a string s, find the longest palindromic substring in s. You may assume that the maximum 
length of s is 1000.
"""

DEBUG_LEVEL = 0

def is_palindrom(s):
    for i in range(int(len(s)/2)):
        if s[i] != s[len(s)-i-1]:
            return False

    return True

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str

        Brute force soluition
        """
        slen = len(s)

        for plen in range(slen, 1, -1):
            for i in range(slen - plen + 1):
                if is_palindrom(s[i:i+plen]):
                    return s[i:i+plen]

        return s[0]
        
def test_driver(s, expected_result):
    print(
        's: {}, expected: {}'.format(
            s, 
            expected_result))

    sol = Solution()
    actual_result = sol.longestPalindrome(s)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample_01():
    test_driver('babad', 'bab')

def test_sample_02():
    test_driver('cbbd', 'bb')

def test_01():
    test_driver('kikiriki', 'ikiriki')

test_sample_01()
test_sample_02()
test_01()
