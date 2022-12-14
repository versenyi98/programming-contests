from heapq import heappush, heappop
from bisect import bisect_right

class Solution(object):
    def maxPoints(self, grid, queries):
        """
        :type grid: List[List[int]]
        :type queries: List[int]
        :rtype: List[int]
        """

        width = len(grid[0])
        height = len(grid)

        pq = []
        heappush(pq, (grid[0][0], (0, 0)))

        directions = [(-1, 0), (+1, 0), (0, -1), (0, +1)]
        seen = set()

        maximums = []

        while pq:
            value_so_far, position = heappop(pq)
            if position in seen:
                continue
            seen.add(position)
            maximums.append(value_so_far + 1)
            x, y = position

            for direction in directions:
                dx, dy = direction
                nx, ny = x + dx, y + dy

                if 0 <= nx < width and 0 <= ny < height:
                    new_pos = (nx, ny)
                    if new_pos in seen:
                        continue
                    new_val = max(value_so_far, grid[ny][nx])
                    heappush(pq, (new_val, (nx, ny)))
        return [bisect_right(maximums, q) for q in queries]