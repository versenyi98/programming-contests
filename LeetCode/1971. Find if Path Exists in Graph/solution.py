class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        visited = set([source])

        connected = {key: [] for key in range(n)}
        for s, d in edges:
            connected[s].append(d)
            connected[d].append(s)

        queue = [source]

        while queue and queue[0] != destination:
            head = queue.pop(0)

            for other in connected[head]:
                if other not in visited:
                    visited.add(other)
                    queue.append(other)

        return len(queue) 