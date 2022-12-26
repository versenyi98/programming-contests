class Solution:
    def canJump(self, nums: List[int]) -> bool:
        current_max = 0
        for idx, value in enumerate(nums):
            if idx > current_max:
                return False
            current_max = max(current_max, idx + value)
        return True