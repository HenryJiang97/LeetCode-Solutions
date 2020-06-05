const int mod = 1e9 + 7;

class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        for (int i = 0; i <= n; i++)    dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                long sum = mod + dp[i - 1][j] - (j - i >= 0 ? dp[i - 1][j - i] : 0);
                dp[i][j] = (dp[i][j - 1] + sum) % mod;
            }
        }
        return (int)dp[n][k];
    }
};