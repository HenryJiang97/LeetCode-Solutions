class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.length();
        
        int MAX = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (s[i - 1] == s[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                MAX = max(MAX, dp[i][j]);
            }
        }
        
        return MAX;
    }
};