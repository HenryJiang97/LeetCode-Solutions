const int mod = 1e9 + 7;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(6, vector<int>(16)));
        for (int i = 0; i < 6; i++)    dp[0][i][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int cur = 0; cur < 6; cur++) {
                int constraint = rollMax[cur];
                
                // Different from last roll
                for (int prev = 0; prev < 6; prev++) {
                    if (cur == prev)    continue;
                    for (int con = 1; con <= 15; con++) {
                        dp[i][cur][1] = (dp[i][cur][1] + dp[i - 1][prev][con]) % mod;   
                    }
                }
                
                // Same as the last roll
                for (int con = 1; con <= constraint; con++) {
                    dp[i][cur][con] = (dp[i][cur][con] + dp[i - 1][cur][con - 1]) % mod;
                }
            }
        }
        
        // Get result
        int res = 0;
        for (int cur = 0; cur < 6; cur++) {
            for (int con = 1; con <= 15; con++) {
                res = (res + dp[n - 1][cur][con]) % mod;
            }
        }
        
        return res;
    }
};