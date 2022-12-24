import math
from collections import Counter


class Solution:
    def countAnagrams(self, s: str) -> int:
        res = 1
        for word in s.split():
            whole = math.factorial(len(word))
            counter = Counter(list(word))
            for key, item in counter.items():
                whole //= math.factorial(item)
            res *= whole
        return res % 1000000007
