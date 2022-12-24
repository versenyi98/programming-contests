class Solution:
    def maxStarSum(self, vals: List[int], edges: List[List[int]], k: int) -> int:
        maximum_star_sum = None

        connected = {}
        for edge in edges:
            f, t = edge
            if not (f in connected):
                connected[f] = []
            if not (t in connected):
                connected[t] = []
            connected[t].append(f)
            connected[f].append(t)

        for idx, value in enumerate(vals):
            if maximum_star_sum is None:
                maximum_star_sum = value
            current_star_sum = value
            if idx in connected:
                neighbours = sorted([vals[other_idx] for other_idx in connected[idx]], reverse=True)
                current_size = 0
                while current_size < len(neighbours) and current_size != k and neighbours[current_size] >= 0:
                    current_star_sum += neighbours[current_size]
                    current_size += 1
            maximum_star_sum = max(current_star_sum, maximum_star_sum)

        return maximum_star_sum