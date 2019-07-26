// 2D-DP
// dp[i][j] => number of valid permutations of i, which ends with j
// if (S[i] == 'D')    dp[i][j] = dp[i - 1][j, j + 1, j + 2, ... , i - 1];
// if (S[i] == 'I')    dp[i][j] = dp[i - 1][0, 1, 2, ... , j - 1];

class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.length();
        int mod = 1e9 + 7;
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        dp[0][0] = 1;
            
        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (S[i - 1] == 'D') {
                    for (int k = j; k < i; k++) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                } else {
                    for (int k = 0; k < j; k++) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        
        int res = 0;
        for (auto& a : dp[n]) {
            res += a;
            res %= mod;
        }
        return res;
    }
};