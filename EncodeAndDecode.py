from typing import List

def encode(strs: List[str]) -> str:

    out = ""
    if len(strs) == 0:
        return None
    if len(strs) == 1:
        out = out + strs[0]
        return out
    for s in strs:
        slen = len(s)
        if slen < 10:
            slen_str = "00" + str(slen)
        elif slen < 100:
            slen_str = "0" + str(slen)
        else:
            slen_str = str(slen)

        s = slen_str + s
        out = out + s
    return out

def decode(s: str) -> List[str]:
    ptr = 0
    out = []
    if s == None:
        return []
    total_len = len(s)
    print(s)
    print(len(s))
    if len(s) == 0:
        out.append(s)
        return out
    while ptr < total_len:
        slen_str = s[ptr:ptr+3]
        print(slen_str)
        while slen_str[0] == '0':
            slen_str = slen_str[1:]
        slen = int(slen_str)
        start = ptr+3
        new_s = s[start:start+slen]
        print(new_s)
        out.append(new_s)
        ptr = start+slen
    return out


if __name__ == "__main__":
    s = encode([])
    print(decode(s))