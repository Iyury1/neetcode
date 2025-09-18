class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) == len(s):
            tmap = {}
            smap = {}
            for c in t:
                tmap[c] = 1 + tmap.get(c, 0)
            same = True
            for c in s:
                smap[c] = 1 + smap.get(c,0)
            for c in s:
                if c not in tmap or tmap[c] != smap[c]:
                    same = False
            if same:
                return s
            return ""
        if len(t) > len(s):
            return ""
        tmap = {}
        smap = {}
        for c in t:
            tmap[c] = 1 + tmap.get(c, 0)
        l = 0
        r = 0
        found = False
        print("Searching")
        while r < len(s):
            print(smap)
            smap[s[r]] = 1 + smap.get(s[r], 0)
            full = True
            for c in tmap:
                if c not in smap:
                    full = False
                    break
            if full:
                found = True
                break
            r = r + 1
        if not found:
            return ""
        z = r + 1
        extra = 0
        print("Adding extras")
        while z < len(s):
            if s[z] in tmap:
                extra = z-r
            z = z + 1
        for i in range(1, extra+1):
            print("added ", s[r+i])
            smap[s[r+i]] = 1 + smap.get(s[r+i],0)
            print(smap)
        print("r = ", r, ", extra = ", extra)
        r = r + extra
        print("Removing")
        while l < r:
            print(smap)
            smap[s[l]] = smap[s[l]] - 1
            full = True
            for c in tmap:
                if c not in smap or smap[c] <= 0:
                    full = False
                    break
            if not full:
                break
            l = l + 1
        if l == r:
            return s[l]
        res = ""
        for i in range(l, r+1):
            res = res + s[i]
        print("l = ", l, ", r = ", r)
        return res
