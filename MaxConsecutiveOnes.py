from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max_ones = 0
        count = 0
        for n in nums:
            if n == 1:
                count += 1
                max_ones = max(max_ones, count)
            else:
                count = 0
        return max_ones;