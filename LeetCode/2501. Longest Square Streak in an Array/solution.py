class Solution(object):
    def longestSquareStreak(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        num_set = set(nums)
        already_seen = set()
        maximum = 0
        nums = sorted(nums)

        for num in nums:
            current = 1
            if num in already_seen:
                continue

            while num ** 2 in num_set:
                current += 1
                already_seen.add(num)
                num = num ** 2
            maximum = max(maximum, current)
        return maximum if maximum > 1 else -1