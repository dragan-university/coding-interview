from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        onums = nums[:]
        nums.sort()
        
        b = 0
        e = len(nums) - 1
        
        while b < e:
            if nums[b] + nums[e] < target:
                b += 1
            elif nums[b] + nums[e] > target:
                e -= 1
            else:
                if nums[b] == nums[e]:
                    return [self.findIndex(onums, nums[b], 1), self.findIndex(onums, nums[e], 2)]
                else:
                    return [self.findIndex(onums, nums[b], 1), self.findIndex(onums, nums[e], 1)]
            
        raise Exception('No solution for twoSum!')
    
    def findIndex(self, nums: List[int], element: int, count: int) -> int:
        """
        Find 'count' occurence of the 'element' in the list 'nums'

        Example: findIndex([1,7,4,7,9,1], 7, 2) returns 3
        """
        i = 0
        c = 1
        
        for num in nums:
            if num == element:
                if c == count:
                    return i
                else:
                    c += 1
            
            i += 1
            