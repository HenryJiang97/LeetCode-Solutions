class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> m(n, vector<int>(n));    // Max value with in a range
        for (int i = 0; i < n; i++)    m[i][i] = arr[i];
        
        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + m[i][k] * m[k + 1][j]);
                }
                m[i][j] = max(m[i][j - 1], arr[j]);
            }
        }
        
        return dp[0][n - 1];
    }
};