import bisect

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        sorted_nums = sorted(nums)

        sums = [0]
        for num in sorted_nums:
            sums.append(sums[-1] + num)
        result = []
        for query in queries:
            pos = bisect.bisect_left(sums, query)
            if pos == len(sums) or sums[pos] != query:
                result.append(pos - 1)
            else:
                result.append(pos)
        return result