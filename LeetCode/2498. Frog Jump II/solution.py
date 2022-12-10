class Solution:
    def maxJump(self, stones: List[int]) -> int:
        max_dist = 0

        for idx, val in enumerate(stones):
            for other in [idx + 1, idx + 2]:
                if other < len(stones):
                    max_dist = max(max_dist, stones[other] - val)
        return max_dist
