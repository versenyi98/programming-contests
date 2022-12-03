from collections import Counter


class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        counter1 = Counter(list(word1))
        counter2 = Counter(list(word2))

        keys1 = sorted(list(counter1.keys()))
        keys2 = sorted(list(counter2.keys()))

        values1 = sorted(list(counter1.values()))
        values2 = sorted(list(counter2.values()))

        return values1 == values2 and keys1 == keys2
