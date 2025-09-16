from typing import List

def longestConsecutive(nums: List[int]) -> int:
    num_set = set()
    for num in nums:
        num_set.add(num)
    max_count = 0
    for num in nums:
        if num-1 not in num_set:
            count = 1
            # sequence start
            while num+count in num_set:
                count = count +1
            if count > max_count:
                max_count = count
    return max_count