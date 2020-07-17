class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        
        vector<vector<vector<bool>>> dp(n3 + 1, vector<vector<bool>>(n1 + 1, vector<bool>(n2 + 1)));
        dp[0][0][0] = 1;
        
        for (int i3 = 1; i3 <= n3; i3++) {
            // Last char come from s1
            for (int i1 = 1; i1 <= n1; i1++) {
                if (s1[i1 - 1] != s3[i3 - 1])    continue;
                for (int i2 = 0; i2 <= n2; i2++) {
                    dp[i3][i1][i2] = dp[i3][i1][i2] || dp[i3 - 1][i1 - 1][i2];
                }
            }
            
            // Last char come from s2
            for (int i2 = 1; i2 <= n2; i2++) {
                if (s2[i2 - 1] != s3[i3 - 1])    continue;
                for (int i1 = 0; i1 <= n1; i1++) {
                    dp[i3][i1][i2] = dp[i3][i1][i2] || dp[i3 - 1][i1][i2 - 1];
                }
            }
        }
        
        return dp[n3][n1][n2];
    }
};