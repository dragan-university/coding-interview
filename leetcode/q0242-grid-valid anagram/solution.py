"""
242 - https://leetcode.com/problems/valid-anagram/

Note: recommended in GridU course Coding Technical Interview
"""

DEBUG_LEVEL = 0

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        sd = {}
        td = {}
        
        for c in s:
            if c in sd:
                sd[c] = sd[c] + 1
            else:
                sd[c] = 1
        
        for c in t:
            if c in td:
                td[c] = td[c] + 1
            else:
                td[c] = 1
        
        return sd == td
        
def test_driver(s: str, t: str, expected_result: bool):
    print(
        's: {}, t: {}, expected: {}'.format(
            s,
            t, 
            expected_result))

    sol = Solution()
    actual_result = sol.isAnagram(s, t)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample_01():
    test_driver("anagram", "nagaram", True)

def test_sample_02():
    test_driver("rat", "car", False)

test_sample_01()
test_sample_02()
