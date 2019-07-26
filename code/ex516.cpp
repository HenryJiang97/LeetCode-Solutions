class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();    if (n == 0)    return 0;
        
        auto dp = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        
        for (int l = 2; l <= n; l++) {
            for (int start = 0; start < n - l + 1; start++) {
                int i = start, j = i + l - 1;
                
                if (s[i] == s[j])    dp[i][j] = dp[i + 1][j - 1] + 2;
                else    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[0][n - 1];
    }
};