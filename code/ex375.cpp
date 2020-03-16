class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                int MIN = INT_MAX;
                for (int k = i; k <= j; k++) {
                    MIN = min(MIN, max(i <= k - 1 ? dp[i][k - 1] : 0, 
                                       k + 1 <= j ? dp[k + 1][j] : 0) + k);
                }
                dp[i][j] = MIN;
            }
        }
        return dp[1][n];
    }
};