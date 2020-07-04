class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length(), np = p.length();
        
        // Define dp and init
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1));
        dp[0][0] = 1;
        for (int j = 1; j <= np; j++)
            if (p[j - 1] == '*')    dp[0][j] = 1;
            else    break;
        
        // Build dp
        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= np; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
                }
            }
        }
        
        return dp[ns][np];
    }
};