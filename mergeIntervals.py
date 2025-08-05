from typing import List

def merge(intervals: List[List[int]]) -> List[List[int]]:
    sorted_intervals = sorted(intervals)
    print(sorted_intervals)
    result = sorted_intervals.copy()
    curr_start = sorted_intervals[0][0]
    n = 0
    for i in range(len(intervals)):
        if sorted_intervals[i][0] > curr_start:
            curr_start = sorted_intervals[i][0]
            result = result[(n-1):]
        else:
            n = n + 1

    for i in range(1, len(result)):
        if result[i][0] == result[i-1][1]:
            result[i-1][1] = result[i][1]
            result.pop(i)
    return result

if __name__ == "__main__":
    print(merge([[1,3],[1,5],[6,7]]))