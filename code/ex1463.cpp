class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        const int dir[3] = {-1, 0, 1};
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        dp[0][n - 1] = grid[0][0] + grid[0][n - 1];
        
        int MAX = 0;
        for (int i = 1; i < m; i++) {
            vector<vector<int>> bkp = dp;
            for (int r1 = 0; r1 < n; r1++) {
                for (int r2 = 0; r2 < n; r2++) {
                    for (int d1 : dir) {
                        int p1 = r1 + d1;
                        if (p1 < 0 || p1 >= n)    continue;
                        for (int d2 : dir) {
                            int p2 = r2 + d2;
                            if (p2 < 0 || p2 >= n)    continue;
                            int gain = r1 == r2 ? grid[i][r1] : grid[i][r1] + grid[i][r2];
                            dp[r1][r2] = max(dp[r1][r2], bkp[p1][p2] + gain);
                        }
                    }
                    if (i == m - 1)    MAX = max(MAX, dp[r1][r2]);
                }
            }
        }
        
        return MAX;
    }
};