class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // 1 digit code for the ending
            if (s[i - 1] >= '1' && s[i - 1] <= '9')
                dp[i] += dp[i - 1];
            // 2 digits code for the ending
            if (i - 2 >= 0 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6'))
                dp[i] += dp[i - 2];
        }
        
        return dp[n];
    }
};