class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();    if (n == 0)    return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = 1 + dp[i + 1][j];
                for (int k = i + 1; k <= j; k++) {
                    if (s[k] == s[i]) {
                        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};