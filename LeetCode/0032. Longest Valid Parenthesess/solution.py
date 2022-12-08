class Solution:
    def longestValidParentheses(self, s: str) -> int:
        counter = 0
        points = {}
        max_points = 0
        for idx, p in enumerate(s):
            counter += 1 if p == '(' else -1
            if p == ')' and counter >= 0:
                if counter not in points:
                    points[counter] = 0
                points[counter] += 2 + (points[counter + 1] if counter + 1 in points else 0)
                points[counter + 1] = 0
                max_points = max(max_points, points[counter])
            if counter < 0:
                counter = 0
                points.clear()
        return max_points