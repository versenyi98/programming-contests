class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        in_row, in_col = {}, {}
        visited = [False] * len(stones)
        for idx, (row, col) in enumerate(stones):
            if row not in in_row:
                in_row[row] = []
            if col not in in_col:
                in_col[col] = []

            in_row[row].append(idx)
            in_col[col].append(idx)

        groups = 0

        for idx, _ in enumerate(stones):
            if not visited[idx]:
                groups += 1

                queue = [idx]

                while queue:
                    head = queue.pop(0)
                    if visited[head]:
                        continue
                    visited[head] = True
                    row, col = stones[head]

                    queue += in_row[row] + in_col[col]

        return len(stones) - groups