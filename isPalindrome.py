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

def isPalindrome(s: str) -> bool:
    print(len(s))
    new_s = ""
    for c in s:
        if c.isalnum():
            new_s = new_s + c
    print(len(new_s))

    for i in range(int(len(new_s)/2)):
        print("Current char = ", new_s[i], ", Opposing char = ", new_s[-(i+1)])
        if new_s[i].lower() != new_s[-(i+1)].lower():
            return False
    return True


if __name__ == "__main__":
    if isAnagram("jar", "jam"):
        print("Pass")
