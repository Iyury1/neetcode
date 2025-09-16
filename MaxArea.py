from typing import List

class Solution:

    def _checkWater(self, height, length):
        area = height * length
        print("Area = ", area)
        if area > self.res:
            self.res = area

    def maxArea(self, heights: List[int]) -> int:
        self.res = 0

        l, r = 0, len(heights) - 1

        while l < r:
            print("l = ", l, ", r = ", r, ", length = ", (r-l))
            print("height[l] = ", heights[l], ", height[r] = ", heights[r])
            self._checkWater(min(heights[l], heights[r]), (r-l))

            lnext = l+1
            if lnext >= r:
                print("breaking")
                break
            print("lnext = ", lnext, ", r = ", r, ", length = ", (r-lnext))
            print("height[lnext] = ", heights[lnext], ", height[r] = ", heights[r])

            self._checkWater(min(heights[lnext], heights[r]), (r-lnext))
            rnext = r-1
            if l >= rnext:
                break
            print("l = ", l, ", rnext = ", rnext, ", length = ", (rnext-l))
            print("height[l] = ", heights[l], ", height[rnext] = ", heights[rnext])

            self._checkWater(min(heights[l], heights[rnext]), (rnext-l))
            l = lnext
            r = rnext

        return self.res
    
if __name__ == "__main__":
    solution = Solution()
    res = solution.maxArea([1,7,1,1,1,1,2,5,12,3,500,50,7,8,4,7,38,9,10,12,6])
    print("res = ", res)