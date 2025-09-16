class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        h = 0
        res = 0
        if len(s) > 0:
            res = 1
        charmap = set()
        while h < len(s) and l <= h:
            print("l=", s[l], " h=", s[h])
            if s[h] not in charmap:
                charmap.add(s[h])
                h = h + 1
                res = max(res, len(charmap))
            else:
                charmap.remove(s[l])
                l = l + 1
            print(charmap)
        return res