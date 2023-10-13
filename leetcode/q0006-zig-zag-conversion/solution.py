"""
6 - https://leetcode.com/problems/zigzag-conversion/description/

n = 4, m = 100

00    06    12
01 05 07 11 13
02 04 08 10 14
03    09    15

n = 5, m = 100

00    08    16    0*(n-1) x*(x-x) 2*(n-1) x*(x-x) 4*(n-1) 
01 07 09 15 17    
02 06 10 14 18
03 05 11 13 19
04    12    20

4+2+4+2+4   100/6 = 16(4)
5+3+5+3+5   100/8 = 12(4)
"""

DEBUG_LEVEL = 0

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        
def test_driver(nums1, nums2, expected_result):
    print(
        'nums1: {}, nums2: {}, expected: {}'.format(
            nums1,
            nums2, 
            expected_result))

    sol = Solution()
    actual_result = sol.findMedianSortedArrays(nums1, nums2)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample_01():
    test_driver([1, 3], [2], 2.0)

def test_sample_02():
    test_driver([1, 2], [3, 4], 2.5)

test_sample_01()
test_sample_02()
