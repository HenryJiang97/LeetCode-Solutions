class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ns = s.length(), nt = t.length();
        
        vector<vector<bool>> dp(nt + 1, vector<bool>(ns + 1));
        for (int i = 0; i <= nt; i++)    dp[i][0] = 1;
        
        for (int i = 1; i <= nt; i++) {
            for (int j = 1; j <= ns; j++) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[nt][ns];
    }
};