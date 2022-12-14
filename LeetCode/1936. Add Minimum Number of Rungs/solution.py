class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        rungs = [0] + rungs
        steps = [rungs[i + 1] - v for i, v in enumerate(rungs) if i + 1 < len(rungs)]
        filtered_steps = list(filter(lambda x: x > dist, steps))
        ret = sum(map(lambda x: x // dist - (1 if x % dist == 0 else 0), filtered_steps))

        return ret