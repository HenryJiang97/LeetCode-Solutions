class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();    if (n == 0)    return 0;

        vector<int> hold(n);
        vector<int> notHold(n);
        hold[0] = -prices[0];
        
        for (int i = 1; i < n; i++) {
            hold[i] = max(hold[i - 1], max(-prices[i], notHold[i - 1] - prices[i]));
            notHold[i] = max(notHold[i - 1], hold[i - 1] + prices[i] - fee);
        }
        
        return notHold[n - 1];
    }
};