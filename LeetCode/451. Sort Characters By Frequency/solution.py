from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        counter = Counter()
        counter.update(list(s))
        result = ""

        for entry in counter.most_common():
            letter, amount = entry
            result += letter * amount
        return result
