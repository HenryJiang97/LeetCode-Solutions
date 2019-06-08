// DP (bottom up)

class Solution {
public:
    double soupServings(int N) {
        int n = N / 25 + ((N % 25 != 0) ? 1 : 0);
        // if (n >= 200)    return 1.0;
        
        // DP array init
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        for (int i = 1; i <= n; i++)    dp[0][i] = 1.0;
        dp[0][0] = 0.5;
        
        // Build DP array
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                dp[a][b] += ((double)1 / 4) * dp[a - 4 >= 0 ? a - 4 : 0][b];             
                dp[a][b] += ((double)1 / 4) * dp[a - 3 >= 0 ? a - 3 : 0][b - 1 >= 0 ? b - 1 : 0];                
                dp[a][b] += ((double)1 / 4) * dp[a - 2 >= 0 ? a - 2 : 0][b - 2 >= 0 ? b - 2 : 0];
                dp[a][b] += ((double)1 / 4) * dp[a - 1 >= 0 ? a - 1 : 0][b - 3 >= 0 ? b - 3 : 0];
            }
        }
        
        return dp[n][n];
    }
};