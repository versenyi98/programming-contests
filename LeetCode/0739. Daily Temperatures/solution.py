class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []
        res = []
        for idx in range(len(temperatures) - 1, -1, -1):
            temp = temperatures[idx]
            if not stack:
                res.append(0)
                stack.append((temp, idx))
            else:
                waiting = 0
                while stack and stack[-1][0] <= temp:
                    stack.pop(-1)
                if stack:
                    res.append(stack[-1][1] - idx)
                else:
                    res.append(0)
                stack.append((temp, idx))
        return res[::-1]