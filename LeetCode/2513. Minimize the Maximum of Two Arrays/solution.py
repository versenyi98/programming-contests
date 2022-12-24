import math


class Solution:
    def minimizeSet(self, divisor1: int, divisor2: int, uniqueCnt1: int, uniqueCnt2: int) -> int:
        start_point = uniqueCnt1 + uniqueCnt2

        while True:
            cant1 = start_point // divisor1
            cant2 = start_point // divisor2
            cant_both = start_point // math.lcm(divisor1, divisor2)

            cant1 -= cant_both
            cant2 -= cant_both

            good1 = start_point - cant1 - cant_both
            good2 = start_point - cant2 - cant_both
            good_both = start_point - cant1 - cant2 - cant_both

            if good1 >= uniqueCnt1 and good2 >= uniqueCnt2 and good_both + cant1 + cant2 >= uniqueCnt1 + uniqueCnt2:
                return start_point
            next_ = max(uniqueCnt1 - good1, uniqueCnt2 - good2, uniqueCnt1 + uniqueCnt2 - good_both - cant1 - cant2, 0)
            start_point += next_
