class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        minimum = 10e6
        maximum = 0
        for price in prices:
            minimum = min(minimum, price)
            maximum = max(maximum, price - minimum)

        return maximum