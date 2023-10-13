"""
1 - Two Sum
https://leetcode.com/problems/two-sum/description/
"""

DEBUG_LEVEL = 10

class Solution(object):
    # assume nums is sorted
    def twoSumSorted(self, nums, target):
        """
        :type nums: list
        :type target: int
        :rtype: list
        """
        if len(nums) < 2:
            return []

        left = 0
        right = 1

        while left < right:
            if nums[left] + nums[right] == target:
                return [left, right]

            if nums[left] + nums[right] < target:
                if right < len(nums)-1:
                    right += 1
                else:
                    left += 1

            if nums[left] + nums[right] > target:
                right -= 1
                left += 1

        return []
            
    def twoSum(self, nums, target):
        """
        :type nums: list
        :type target: int
        :rtype: list
        """
        if len(nums) < 2:
            return []

        complements = {}

        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in complements:
                return [complements[complement], i]

            complements[nums[i]] = i

        return []

def test_driver(nums, target, expected_result):
    print(
        'nums: {}, target: {}, expected: {}'.format(
            nums, 
            target, 
            expected_result))

    sol = Solution()
    actual_result = sol.twoSum(nums, target)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver([2, 7, 11, 15], 9, [0, 1])

def test_001():
    test_driver([2, 7, 11, 15, 29], 26, [2, 3])

test_sample()
test_001()
