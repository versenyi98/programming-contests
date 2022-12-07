class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for idx, num in enumerate(nums):
            try:
                other_idx = nums.index(target - num)
                if other_idx != idx:
                    return [idx, other_idx]
            except ValueError:
                continue