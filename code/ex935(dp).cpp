const int dir[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
const int mod = 1e9 + 7;

class Solution {
public:
    int knightDialer(int N) {
        vector<vector<int>> dp(N + 1, vector<int>(12));
        for (int i = 0; i < 12; i++)
            if (i != 9 && i != 11)
                dp[1][i] = 1;
        
        for (int n = 2; n <= N; n++) {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i * 3 + j == 9 || i * 3 + j == 11)    continue;
                    for (auto& d : dir) {
                        int pi = i + d[0], pj = j + d[1];
                        if (pi < 0 || pj < 0 || pi >= 4 || pj >= 3)    continue;
                        if (pi * 3 + pj == 9 || pi * 3 + pj == 11)    continue;
                        dp[n][i * 3 + j] = (dp[n][i * 3 + j] + dp[n - 1][pi * 3 + pj]) % mod;
                    }
                }
            }
        }
        
        int ret = 0;
        for (int i = 0; i < 12; i++)
            if (i != 9 && i != 11)
                ret = (ret + dp[N][i]) % mod;
        return ret;
    }
};