class Solution(object):
    def minFallingPathSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        best = matrix[0]

        for row in matrix[1:]:
            next_best = [0] * len(best)
            for i, val in enumerate(row):
                next_best[i] = min([val + best[j] for j in [i - 1, i, i + 1] if 0 <= j < len(row)])
            best = next_best

        return min(best)
