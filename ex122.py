class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        if len(prices) == 0:
            return 0

        profit = 0

        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:   profit += (prices[i] - prices[i - 1])
            else:   continue

        return profit


sol = Solution()
print(sol.maxProfit([1,2,3,4,5]))
