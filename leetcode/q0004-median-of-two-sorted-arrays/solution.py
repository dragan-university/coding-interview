"""
4 - https://leetcode.com/problems/median-of-two-sorted-arrays/description/
"""

DEBUG_LEVEL = 0

class Solution(object):
    def findMedianSortedArrays1(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float

        Brute force solution - combine two sorted arrays into one and find median

        Time: O(m+n)
        Space: O(m+n)
        """
        # combine two arrays into one
        nums = []
    
        i1 = 0
        i2 = 0
        i = 0

        while i1 < len(nums1) and i2 < len(nums2):
            #print("i1={}, i2={}, i={}".format(i1, i2, i))
            if nums1[i1] < nums2[i2]:
                nums.append(nums1[i1])
                i1 += 1
            else:
                nums.append(nums2[i2])
                i2 += 1
            
            i +=1

        while i1 < len(nums1):
            nums.append(nums1[i1])
            i += 1
            i1 += 1

        while i2 < len(nums2):
            nums.append(nums2[i2])
            i += 1
            i2 += 1
            
        l = len(nums)
        if l%2 == 1:
            return float(nums[int((l-1)/2)])
        else:
            m = int(l/2)
            return (nums[m-1] + nums[m]) / 2.0

    def findMedianSortedArrays2(self, nums1, nums2):
        """
        NOTE: NOT TESTED YET!!!

        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float

        Binary search solution

        Let's assume we have two sorted arrays a[1],...,a[m] and b[1],...b[n]
        and m<n
        
        This is based on the fact when we find point 'i' in first array such that
        a[i] < b[(m+n)/2] and a[i+1] > b[(m+n)/2-1] then median is max(a[i], b[(m+n)/2-1])
        if m+n is odd, or (max(a[i], b[(m+n)/2-1]) + min(a[i+1], b[(m+n)/2])/2)
        if m+n is even

        We perform binary search on 'a' to find such point.

        Time: O(log(m))
        Space: O(1)
        """
        if len(nums1) < len(nums2):
            nums1, nums2 = nums2, nums1

        m = len(nums1)
        n = len(nums2)

        i = m/2

        while i>0 and i<m:
            j = (m+n)/2 - i
        
            if nums1[i-1] < nums2[j]:
                if nums1[i] > nums2[j-1]:
                    if (m+n)%2:
                        return (max+min)/2.0
                    else:
                        return min(nums1[i], nums2[j])
                else:
                    i = (i+m)/2
            else:
                i = i/2

        j = (m+n)/2 - i
        if (m+n)%2:
            return nums2[j]
        else:
            return (nums2[j]+nums2[j+1])/2.0

def test_driver(nums1, nums2, expected_result):
    print(
        'nums1: {}, nums2: {}, expected: {}'.format(
            nums1,
            nums2, 
            expected_result))

    sol = Solution()
    actual_result = sol.findMedianSortedArrays1(nums1, nums2)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample_01():
    test_driver([1, 3], [2], 2.0)

def test_sample_02():
    test_driver([1, 2], [3, 4], 2.5)

def test_01():
    test_driver([1, 2, 3], [1, 2, 3], 2.0)

test_sample_01()
test_sample_02()
test_01()
