class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        
        // Define and init dp array
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, INT_MAX / 2));
        dp[0][0] = 0;
        for (int i = 1; i <= n1; i++)    dp[i][0] = dp[i - 1][0] + 1;
        for (int j = 1; j <= n2; j++)    dp[0][j] = dp[0][j - 1] + 1;
        
        // Build dp array
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) + 1);
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        
        return dp[n1][n2];
    }
};