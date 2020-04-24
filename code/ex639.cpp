const int mod = 1e9 + 7;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        
        vector<long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '*') {    // Ending with star
                // Take one digit from the end
                dp[i] = (dp[i] + dp[i - 1] * 9) % mod;
                // Take two digits from the end
                if (i - 2 >= 0) {
                    if (s[i - 2] == '1') {
                        dp[i] = (dp[i] + dp[i - 2] * 9) % mod;
                    } else if (s[i - 2] == '2') {
                        dp[i] = (dp[i] + dp[i - 2] * 6) % mod;
                    } else if (s[i - 2] == '*') {
                        dp[i] = (dp[i] + dp[i - 2] * 15) % mod;
                    }
                }
            }
            else {    // Ending with non-star
                // Take one digit from the end
                if (s[i - 1] != '0')
                    dp[i] = (dp[i] + dp[i - 1]) % mod;
                // Take two digits from the end
                if (i - 2 >= 0) {
                    if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6') {
                        dp[i] = (dp[i] + dp[i - 2]) % mod;
                    } else if (s[i - 2] == '*') {
                        if (s[i - 1] >= '0' && s[i - 1] <= '6')
                            dp[i] = (dp[i] + dp[i - 2] * 2) % mod;
                        else
                            dp[i] = (dp[i] + dp[i - 2]) % mod;
                    }
                }
            }
        }
        
        return dp[n];
    }
};