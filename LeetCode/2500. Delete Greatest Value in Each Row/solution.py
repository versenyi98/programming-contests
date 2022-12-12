class Solution(object):
    def deleteGreatestValue(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        res = 0
        grid = [sorted(row) for row in grid]
        for i in range(len(grid[0])):
            lst = [row[i] for row in grid]
            res += max(lst)
        return res
