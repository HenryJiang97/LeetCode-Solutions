class Solution {
    const int dir[2][2] = {{-1, 0}, {0, -1}};
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (auto d : dir) {
                    int pi = i + d[0], pj = j + d[1];
                    if (pi < 0 || pj < 0)    continue;
                    dp[pi][pj] += dp[i][j];
                }
            }
        }
        
        return dp[0][0];
    }
};