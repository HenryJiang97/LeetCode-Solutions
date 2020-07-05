class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();    if (m == 0)    return 0;
        int n = grid[0].size();    if (n == 0)    return 0;
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)    return 0;
        
        vector<vector<long>> dp(m, vector<long>(n));
        dp[m - 1][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1)    continue;
                if (i + 1 < m)    dp[i][j] = (dp[i][j] + dp[i + 1][j]);
                if (j + 1 < n)    dp[i][j] = (dp[i][j] + dp[i][j + 1]);
            }
        }
        
        return (int)dp[0][0];
    }
};