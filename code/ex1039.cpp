class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int i = 0; i < n; i++)
            dp[i][i + 2] = A[i] * A[(i + 1) % n] * A[(i + 2) % n];
        
        for (int l = 4; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k <= j - 1; k++)
                    dp[i][j] = min(dp[i][j], A[k] * A[i] * A[j] + dp[i][k] + dp[k][j]);
            }
        }
        
        return dp[0][n - 1];
    }
};