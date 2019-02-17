class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        if len(prices) == 0:
            return 0

        profit = 0
        current = prices[0]

        for i in range(1, len(prices)):
            profit = max(profit, prices[i] - current)
            current = min(current, prices[i])

        return profit

sol = Solution()
print(sol.maxProfit([7,1,5,3,6,4]))
