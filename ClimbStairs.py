from typing import List

class Solution:
    def climbStairs(self, n: int) -> int:

        stepMap = {}
        
        def countStairs(i):
            count = 0
            if i in stepMap:
                return stepMap[i]
            if i < 2:
                count += 1
                return count
            else:
                count += self.climbStairs(n-2)
                count += self.climbStairs(n-1)
            stepMap[i] = count
            return count


        return countStairs(n)
