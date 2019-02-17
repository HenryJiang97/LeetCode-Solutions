// DP

class Solution {
    public int maxProfit(int[] prices) {
        // Special situation
        if (prices.length == 0)    return 0;
        
        int length = prices.length;
        int minF = prices[0], maxE = prices[length - 1];
        int[] dpF = new int[length];
        int[] dpE = new int[length];
        
        // Build two dp arrays
        for (int i = 1, j = length - 2; i < length; i++, j--) {
            // From front to end build dpF
            dpF[i] = Math.max(dpF[i - 1], prices[i] - minF);
            minF = Math.min(minF, prices[i]);
            
            // From end to front build dpE
            dpE[j] = Math.max(dpE[j + 1], maxE - prices[j]);
            maxE = Math.max(maxE, prices[j]);
        }

        // Get the final result
        int profit = 0;
        for (int i = 0; i < length - 1; i++) {
            profit = Math.max(profit, dpF[i] + dpE[i + 1]);
        }
        
        return Math.max(profit, dpF[length - 1]);
    }
}