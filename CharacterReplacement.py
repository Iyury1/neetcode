class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l = 0
        r = 0
        charmap = {}
        most = 0
        total = 0
        res = 0
        while r < len(s) and l <= r:
            debug_msg = ""
            for i in range(l, r):
                debug_msg = debug_msg + s[i]
            print(debug_msg)
            if total - most <= k:
                c = s[r]
                print("Added ", c)
                if c in charmap:
                    charmap[c] = charmap[c] + 1
                else:
                    charmap[c] = 1
                most = max(most, charmap[c])
                total = total + 1
                print("Most = ", most, " Total = ", total)
                r = r + 1
                if total - most <= k:
                    res = max(res, total)
                    print("New res = ", res)
            else:
                c = s[l]
                charmap[c] = charmap[c] - 1
                print("Removed ", c)
                most = max(charmap.values())
                total = total - 1
                print("Most = ", most, " Total = ", total)
                l = l + 1

        return res
