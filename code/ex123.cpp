class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();    if (n == 0)    return 0;
        
        int res = 0;
        // Get max profit from head to tail
        vector<int> dp1(n);
        int MIN = prices[0];
        for (int i = 1; i < n; i++) {
            MIN = min(MIN, prices[i]);
            dp1[i] = max(dp1[i], prices[i] - MIN);
        }
        
        // Get max profit fron tail to head
        vector<int> dp2(n);
        int MAX = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            MAX = max(MAX, prices[i]);
            dp2[i] = max(dp2[i + 1], MAX - prices[i]);
            if (i > 0)    res = max(res, dp1[i - 1] + dp2[i]);
        }
        res = max(res, dp2[0]);
        
        return res;
    }
};