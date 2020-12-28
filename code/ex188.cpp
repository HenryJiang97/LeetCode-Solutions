class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();    if (n == 0)    return 0;
        
        vector<vector<int>> notHold(n, vector<int>(k + 1, INT_MIN / 2));
        vector<vector<int>> hold(n, vector<int>(k + 1, INT_MIN / 2));
        notHold[0][0] = 0;
        hold[0][0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                hold[i][j] = max(notHold[i - 1][j] - prices[i], hold[i - 1][j]);
                notHold[i][j] = max(notHold[i - 1][j], j >= 1 ? hold[i - 1][j - 1] + prices[i] : 0);
            }
        }
        
        // Get result
        int MAX = 0;
        for (int j = 0; j <= k; j++) {
            MAX = max(MAX, notHold[n - 1][j]);
        }
        
        return MAX;
    }
};