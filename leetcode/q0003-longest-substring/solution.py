"""
3 - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
"""

DEBUG_LEVEL = 0

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longest_substring = 0
        current_substring = 0
        letters = {}

        idx = 0
        for c in s:
            if DEBUG_LEVEL > 5:
                print('c:{} -- max:{} -- cur:{}'.format(
                    c,
                    longest_substring,
                    current_substring))

            if c in letters:
                longest_substring = max(longest_substring, current_substring)
                cidx = letters[c]
                current_substring = idx - cidx
                letters = {}
                for i in range(cidx+1, idx+1):
                    letters[s[i]] = i
                if DEBUG_LEVEL > 5:
                    print('cidx:{} -- idx:{} -- letters:{}'.format(cidx, idx, letters))
                idx += 1
                continue

            current_substring += 1
            letters[c] = idx
            idx += 1

        longest_substring = max(longest_substring, current_substring)
        return longest_substring
        
def test_driver(s, expected_result):
    print(
        's: {}, expected: {}'.format(
            s, 
            expected_result))

    sol = Solution()
    actual_result = sol.lengthOfLongestSubstring(s)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample_01():
    test_driver('abcabcbb', 3)

def test_sample_02():
    test_driver('bbbbb', 1)

def test_sample_03():
    test_driver('pwwkew', 3)

def test_submit_01():
    test_driver('dvdf', 3)

test_sample_01()
test_sample_02()
test_sample_03()
test_submit_01()
