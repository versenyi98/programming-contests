class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        current_max = 0
        for i, val in enumerate(nums):
            current = val
            if i - 2 >= 0:
                current = max(current, val + nums[i - 2])
            if i - 3 >= 0:
                current = max(current, val + nums[i - 3])
            nums[i] = current
            current_max = max(current_max, current)
        return current_max