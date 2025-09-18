from typing import List

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        m = len(matrix)
        n = len(matrix[0])
        rows, cols = [False] * m, [False] * n
        for i in range(0, m):
            for j in range(0, n):
                if matrix[i][j] == 0:
                    rows[i] = True
                    cols[j] = True
        
        for i in range(0, m):
            for j in range(0, n):
                if rows[i] or cols[j]:
                    matrix[i][j] = 0