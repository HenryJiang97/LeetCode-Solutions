class Solution {
public:
    string minWindow(string S, string T) {
        int ns = S.length(), nt = T.length();
        
        // Get the minimum length of postfix ending at i which T can be a subsequence of it
        vector<vector<int>> dp(ns + 1, vector<int>(nt + 1, INT_MAX / 2));
        for (int i = 0; i <= ns; i++)    dp[i][0] = 0;
        for (int i = 1; i <= ns; ++i) {
            for (int j = 1; j <= nt; j++) {
                if (S[i - 1] == T[j - 1])
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + 1;
                else
                    dp[i][j] = dp[i - 1][j] + 1;
            }
        }
        
        // Get the minimum length overall in S which T can be a subsequence of it
        int MIN = INT_MAX / 2;
        for (int i = 1; i <= ns; i++) 
            MIN = min(MIN, dp[i][nt]);
        if (MIN == INT_MAX)    return "";
        
        // Get the starting point of the minimum s
        for (int i = 1; i <= ns; i++)
            if (dp[i][nt] == MIN)
                return S.substr(i - MIN, MIN);
        
        return "";
    }
};