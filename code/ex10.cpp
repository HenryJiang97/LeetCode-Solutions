class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.length(), np = p.length();
        
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1));
        // Init dp array
        dp[0][0] = 1;
        for (int j = 2; j <= np; j++)
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];    // Match zero of the element before
        
        // Build dp array
        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= np; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')    // Meet with a '.', match previous substring
                    dp[i][j] = dp[i - 1][j - 1];

                else if (p[j - 1] == '*') {    // Meet with a '*'
                    dp[i][j] = dp[i][j] || dp[i][j - 2];    // Match with zero previous char
                    if (j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.'))    // Match one or more previous chars
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
        
        return dp[ns][np];
    }
};