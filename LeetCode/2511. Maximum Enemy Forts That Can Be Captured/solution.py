class Solution:
    def captureForts(self, forts: List[int]) -> int:
        maximum = 0

        from_fort1 = -1
        from_fort2 = -1
        for idx in range(len(forts)):
            ffort = forts[idx]
            bfort = forts[len(forts) - 1 - idx]
            if ffort == -1:
                if from_fort1 != -1:
                    maximum = max(maximum, idx - from_fort1 - 1)
                from_fort1 = -1
            elif ffort == 1:
                from_fort1 = idx

            if bfort == -1:
                if from_fort2 != -1:
                    maximum = max(maximum, from_fort2 - (len(forts) - 1 - idx) - 1)
                from_fort2 = -1
            elif bfort == 1:
                from_fort2 = len(forts) - 1 - idx
        return maximum