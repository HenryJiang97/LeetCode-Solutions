class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++)    dp[i][i] = 0;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = min(dp[i][j], i + 1 > j - 1 ? 0 : dp[i + 1][j - 1]);
                } else {
                    dp[i][j] = min(dp[i][j], min(dp[i + 1][j], dp[i][j - 1]) + 1);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};