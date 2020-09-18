class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), MIN = INT_MAX, MAX = 0;
        for (int i = 0; i < n; i++) {
            MAX = max(MAX, prices[i] - MIN);
            MIN = min(MIN, prices[i]);
        }
        return MAX;
    }
};