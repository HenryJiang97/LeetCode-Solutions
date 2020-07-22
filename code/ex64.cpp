class Solution {
    const int dir[2][2] = {{-1, 0}, {0, -1}};
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    if (m == 0)    return 0;
        int n = grid[0].size();    if (n == 0)    return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX / 2));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0)    continue;
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + grid[ni][nj]);
                }
            }
        }
        
        return dp[0][0];
    }
};