// Create dp list buy and sell
// buy[i] = Math.max(buy[i - 1], sell[i - 2] - buy[i]), due to one day cooldown
// sell[i] = Math.max(sell[i - 1]. buy[i - 1] + sell[i])
// In this implementation, we use buy_1 = buy[i - 1], sell_1 = sell[i - 1], sell_2 = sell[i - 2]


class Solution {
    public int maxProfit(int[] prices) {
        // Special situation
        if (prices.length <= 1)    return 0;
        
        
        int buy = -prices[0], buy_1;
        int sell = 0, sell_1 = sell, sell_2;
        
        for (int i = 1; i < prices.length; ++i) {
            buy_1 = buy;
            sell_2 = sell_1;
            sell_1 = sell;
            
            buy = Math.max(buy_1, sell_2 - prices[i]);           
            sell = Math.max(sell_1, buy_1 + prices[i]);
        }
        
        return sell;
    }
}