class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        mapping = {
            ")": "(",
            "}": "{",
            "]": "["
        }


        for p in s:
            if p in mapping:
                if len(stack) == 0 or stack[-1] != mapping[p]:
                    return False
                stack.pop(-1)
            else:
                stack.append(p)
        return len(stack) == 0