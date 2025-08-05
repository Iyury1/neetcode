from typing import List


def groupAnagrams(strs: List[str]) -> List[List[str]]:

    results = [[]]
    result_maps = {}
    for i, s in enumerate(strs):
        curr_map = {}
        for c in s:
            curr_map[c] = curr_map.get(c, 0) + 1
        if i == 0:
            results[0].append(s)
            result_maps[0] = curr_map
        else:
            existing = False
            for k, v in result_maps.items():
                if curr_map == v:
                    results[k].append(s)
                    existing = True
                    break
            if not existing:
                idx = len(results)
                results.append([s])
                result_maps[idx] = curr_map
    
    return results