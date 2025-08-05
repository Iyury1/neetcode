from typing import List

def twoSum(nums: List[int], target: int) -> List[int]:
    nums_map = {}
    for i, num in enumerate(nums):
        nums_map[num] = i
        difference = target-num
        if difference in nums_map:
            j = nums_map[difference]
            if i == j:
                continue
            return sorted([i, j])
        
if __name__ == "__main__":
    print(twoSum([2, 1, 5, 3], 4))