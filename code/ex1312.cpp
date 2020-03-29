class Solution {
public:
    int minInsertions(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        return s.length() - LCS(s, rs);
    }
    
private:
    int LCS(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[n1][n2];
    }
};