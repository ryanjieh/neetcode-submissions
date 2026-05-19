class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxp = 0
        for i in range(len(prices) - 1):
            sellday = len(prices) - i - 1
            sellprice = prices[sellday]
            buyprice = min(prices[:sellday])
            profit = sellprice - buyprice
            maxp = max(maxp, profit)
            print(i)
        return maxp

