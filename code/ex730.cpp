const int mod = 1e9 + 7;

class Solution {
public:
    int countPalindromicSubsequences(string S) {
        int n = S.length();
        
        // Get prev and next index of each char ('a', 'b', 'c', 'd') for each index
        vector<vector<int>> prev(n, vector<int>(4)), next(n, vector<int>(4));
        
        vector<int> idx(4, -1);
        for (int i = 0; i < n; i++) {
            idx[S[i] - 'a'] = i;
            for (int k = 0; k < 4; k++)
                prev[i][k] = idx[k];
        }
        
        idx = vector<int>(4, n);
        for (int i = n - 1; i >= 0; --i) {
            idx[S[i] - 'a'] = i;
            for (int k = 0; k < 4; k++)
                next[i][k] = idx[k];
        }
        
        // Dynamic programming
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                for (int k = 0; k < 4; k++) {
                    if (next[i][k] < prev[j][k])
                        dp[i][j] = (dp[i][j] + dp[next[i][k] + 1][prev[j][k] - 1] + 1) % mod;
                    if (next[i][k] <= j)
                        dp[i][j] = (dp[i][j] + 1) % mod;
                }
            }
        }
        
        return dp[0][n - 1];
    }
};