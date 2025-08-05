def isAnagram(s: str, t: str) -> bool:
    slen = len(s)
    tlen = len(t)
    if slen != tlen:
        return False
    halflen = int(slen/2)
    for i in range(halflen):
        print(i, " ", s[i], " ", t[-(i+1)])
        if s[i] != t[-(i+1)]:
            return False
    if slen % 2 and s[halflen] != t[halflen]:
        return False
    return True

if __name__ == "__main__":
    if isAnagram("jar", "jam"):
        print("Pass")
