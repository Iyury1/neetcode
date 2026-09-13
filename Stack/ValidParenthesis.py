class Solution:
    def isValid(self, s: str) -> bool:
        open_brackets = ['(', '{', '[']
        close_brackets = [')', '}', ']']
        stack = []

        i = 0
        while i < len(s):
            while i < len(s) and s[i] in open_brackets:
                stack.append(s[i])
                i += 1
            if len(stack) == 0:
                return False
            while i < len(s) and stack:
                b = stack.pop()
                try:
                    bracket_index = open_brackets.index(b)
                except ValueError:
                    return False
                print(s[i], " ", close_brackets[bracket_index])
                if s[i] != close_brackets[bracket_index]:
                    return False
                i += 1
        if stack:
            return False
        return True