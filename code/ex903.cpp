// 2D-DP
// dp[i][j] => number of valid permutations of i, which ends with j
// if (S[i] == 'D')    dp[i][j] = dp[i - 1][j, j + 1, j + 2, ... , i - 1];
// if (S[i] == 'I')    dp[i][j] = dp[i - 1][0, 1, 2, ... , j - 1];

class Solution {
    const int mod = 1e9 + 7;
    int dp[202][202];
public:
    int numPermsDISequence(string S) {
        int n = S.length();
        memset(dp, 0, sizeof(dp));
        
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (S[i - 1] == 'D') {
                    for (int jj = j; jj < i; jj++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][jj]) % mod;
                    }
                } else {
                    for (int jj = 0; jj < j; jj++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][jj]) % mod;
                    }
                }
            }
        }
        
        // Get result
        int res = 0;
        for (int j = 0; j <= n; j++) {
            res = (res + dp[n][j]) % mod;
        }
        
        return res;
    }
};