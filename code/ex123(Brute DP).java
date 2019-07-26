// Brute Force with 1D array dp

class Solution {
    public static int max(int[] prices, int lo, int hi) {
        if (lo >= hi)    return 0;
        
        int maxProfit = 0, minPrice = prices[lo];
        
        for (int i = lo; i <= hi; i++) {
            maxProfit = Math.max(maxProfit, prices[i] - minPrice);
            minPrice = Math.min(minPrice, prices[i]);
        }
        
        return maxProfit;
    }
    
    public int maxProfit(int[] prices) {
        int maxP = 0, profit = 0;
        
        for (int i = 0; i < prices.length; i++) {
            profit = max(prices, 0, i) + max(prices, i + 1, prices.length - 1);
            maxP = Math.max(maxP, profit);
        }
        
        maxP = Math.max(maxP, max(prices, 0, prices.length - 1));
        
        return maxP;
    }
}