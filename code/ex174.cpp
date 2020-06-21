const int dir[2][2] = {{-1, 0}, {0, -1}};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();    if (m == 0)    return 0;
        int n = dungeon[0].size();    if (n == 0)    return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX / 2));
        dp[m - 1][n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                for (auto& d : dir) {
                    int pi = i + d[0], pj = j + d[1];
                    if (pi < 0 || pj < 0 || pi >= m || pj >= n)    continue;
                    dp[pi][pj] = min(dp[pi][pj], max(1, dp[i][j] - dungeon[pi][pj]));
                }
            }
        }
        
        return dp[0][0];
    }
};