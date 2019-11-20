class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)    return 0;
        
        vector<int> hold(n), unHold(n);
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            hold[i] = max(max(hold[i - 1], -prices[i]), i - 2 >= 0 ? unHold[i - 2] - prices[i] : INT_MIN);
            unHold[i] = max(unHold[i - 1], hold[i - 1] + prices[i]);
        }
        
        return unHold[n - 1];
    }
};