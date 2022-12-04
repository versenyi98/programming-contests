import math


class Solution:
    def minimumAverageDifference(self, nums: list[int]) -> int:
        sum_so_far = [0]

        minimum_diff = math.inf
        minimum_index = 0

        for idx in range(len(nums)):
            sum_so_far.append(sum_so_far[-1] + nums[idx])
        for idx in range(len(nums)):
            avg_of_first_half = sum_so_far[idx + 1] // (idx + 1)
            avg_of_second_half = (sum_so_far[-1] - sum_so_far[idx + 1]) // max(1, len(nums) - idx - 1)

            diff = abs(avg_of_second_half - avg_of_first_half)

            if diff < minimum_diff:
                minimum_index = idx
                minimum_diff = diff

        return minimum_index