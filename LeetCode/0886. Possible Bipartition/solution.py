class Solution(object):
    def possibleBipartition(self, n, dislikes):
        """
        :type n: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        group0 = set()
        group1 = set()

        dislike_map = {idx: [] for idx in range(1, n + 1)}
        for p1, p2 in dislikes:
            dislike_map[p1].append(p2)
            dislike_map[p2].append(p1)

        visited = set()
        for idx in range(1, n + 1):
            if (idx, 0) in visited or (idx, 1) in visited:
                continue
            visited.add((idx, 0))
            queue = [(idx, 0)]

            while queue:
                next_idx, group = queue.pop(0)
                if group == 0:
                    group0.add(next_idx)
                else:
                    group1.add(next_idx)

                for disliked in dislike_map[next_idx]:
                    if (disliked, 1 - group) not in visited:
                        visited.add((disliked, 1 - group))
                        queue.append((disliked, 1 - group))
        return len(set.intersection(group0, group1)) == 0
