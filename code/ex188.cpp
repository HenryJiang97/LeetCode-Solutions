class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        // If k is larger than the maximum possible transaction can be made
        // Just simply buy and sell the stock on every single day
        if (k > n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++) {
                profit += max(prices[i] - prices[i - 1], 0);
            }
            return profit;
        }
        
        // Else
        vector<int> dp1(k + 1, INT_MIN / 2);    // Holding stock at i, having made j transactions
        vector<int> dp2(k + 1, INT_MIN / 2);    // Not holding stock at i, having made j transactions
        
        // Base cases
        dp1[0] = 0;
        dp2[0] = 0;
        
        // DP
        int MAX = 0;
        for (int i = 0; i < n; i++) {
            vector<int> backup1 = dp1;
            vector<int> backup2 = dp2;
            for (int j = 1; j <= k; j++) {
                dp1[j] = max(backup1[j], backup2[j - 1] - prices[i]);
                dp2[j] = max(backup2[j], backup1[j] + prices[i]);
                if (i == n - 1)    MAX = max(MAX, dp2[j]);
            }
        }
        
        return MAX;
    }
};