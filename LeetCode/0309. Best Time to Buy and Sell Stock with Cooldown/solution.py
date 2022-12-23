class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        price_len = len(prices)
        hold_position = [None for _ in range(price_len)]
        buy_position = [None for _ in range(price_len)]
        buy_position[0] = 0

        maximum = 0

        for idx in range(price_len):
            holding = hold_position[idx]
            buying = buy_position[idx]

            if holding is not None:
                maximum = max(maximum, holding[0] - holding[1] + prices[idx])

            if holding is not None:
                # HOLD
                if idx + 1 < price_len:
                    if hold_position[idx + 1] is None:
                        hold_position[idx + 1] = holding
                    else:
                        next_hold = hold_position[idx + 1]
                        current = holding[0] - holding[1]
                        next_best = next_hold[0] - next_hold[1]
                        if current > next_best:
                            hold_position[idx + 1] = holding
                # SELL
                if idx + 2 < price_len:
                    next_buy = buy_position[idx + 2]
                    if next_buy is None and prices[idx] > holding[1]:
                        buy_position[idx + 2] = (holding[0] - holding[1] + prices[idx])
                    elif next_buy is not None:
                        if holding[0] - holding[1] + prices[idx] > next_buy:
                            buy_position[idx + 2] = holding[0] - holding[1] + prices[idx]
            if buying is not None:
                if idx + 1 < price_len:
                    # BUY:
                    next_hold = hold_position[idx + 1]
                    holding = (buying, prices[idx])
                    if next_hold is None:
                        hold_position[idx + 1] = holding
                    else:
                        current = holding[0] - holding[1]
                        next_best = next_hold[0] - next_hold[1]
                        if current > next_best:
                            hold_position[idx + 1] = holding
                    # STALL
                    next_buy = buy_position[idx + 1]
                    if next_buy is None:
                        buy_position[idx + 1] = buying
                    else:
                        buy_position[idx + 1] = max(next_buy, buying)
        return maximum