class Solution:
    def numTilings(self, n: int) -> int:
        self.mapping = {}
        self.n = n
        return self.rec(0, 0) % 1000000007

    def rec(self, row1, row2):
        n = self.n
        mapping = self.mapping

        if (row1 == n) and (row2 == n):
            return 1

        if (row1 == n) != (row2 == n):
            return 0

        if row1 > n or row2 > n:
            return 0

        key = (row1, row2)
        if key in mapping:
            return mapping[key]

        mapping[key] = 0

        if row1 == row2:
            mapping[key] += self.rec(row1 + 1, row2 + 1) \
                + self.rec(row1 + 2, row2 + 2) \
                + self.rec(row1 + 1, row2 + 2) \
                + self.rec(row1 + 2, row2 + 1)
        if row1 > row2:
            mapping[key] += self.rec(row1 + 1, row2 + 2) \
                + self.rec(row1, row2 + 2)
        if row1 < row2:
            mapping[key] += self.rec(row1 + 2, row2 + 1) \
                + self.rec(row1 + 2, row2)

        return mapping[key] % 1000000007
