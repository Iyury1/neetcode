from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        r, c = 0, 0
        m = len(matrix)
        n = len(matrix[0])

        res = []
        loops = 0
        print("n = ", n, ", m = ", m, ", n*m = ", n*m)
        while len(res) < (n * m):
            # across top
            print("Loop ", loops)
            print("Going across top")
            while c < n - loops:
                print("Added ", matrix[r][c])
                res.append(matrix[r][c])
                if len(res) == n*m:
                    return res
                c += 1
            c -= 1
            r += 1
            # down right
            print("Going down right")
            while r < m - loops:
                print("Added ", matrix[r][c])
                res.append(matrix[r][c])
                if len(res) == n*m:
                    return res
                r += 1
            r -= 1
            c -= 1
            # across bottom
            print("Back across bottom")
            while c >= loops:
                print("Added ", matrix[r][c])
                res.append(matrix[r][c])
                if len(res) == n*m:
                    return res
                c -= 1
            c += 1
            r -= 1
            loops += 1
            # up left
            print("Back up left")
            while r >= loops:
                print("Added ", matrix[r][c])
                res.append(matrix[r][c])
                if len(res) == n*m:
                    return res
                r -= 1
            r += 1
            c += 1
            
            print("Length of result = ", len(res))

            if loops > 4:
                break

        return res
    
if __name__ is "__main__":
    sol = Solution()
    print(sol.spiralOrder([[6,9,7]]))