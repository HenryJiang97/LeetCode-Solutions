class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        
        vector<int> dp(n, INT_MAX);
        dp[0] = min(costs[0], min(costs[1], costs[2]));
        
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + min(costs[0], min(costs[1], costs[2]));
            for (int j = i - 1; j >= 0 && days[i] - days[j] + 1 <= 30; j--) {
                int day = days[i] - days[j] + 1;
                dp[i] = min(dp[i], j > 0 ? dp[j - 1] + costs[2] : costs[2]);    // 30-day pass
                if (day <= 7)    dp[i] = min(dp[i], j > 0 ? dp[j - 1] + costs[1] : costs[1]);    // 7-day pass
            }
        }
        
        return dp[n - 1];
    }
};