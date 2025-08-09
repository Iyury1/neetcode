from typing import List

def topKFrequent(nums: List[int], k: int) -> List[int]:
    num_map = {}
    for num in nums:
        num_map[num] = num_map.get(num, 0) + 1
    sorted_map = dict(sorted(num_map.items(), key = lambda item: item[1], reverse=True))
    iter_map = iter(sorted_map)
    result = []
    for i in range(k):
        result.append(next(iter_map))

    return result