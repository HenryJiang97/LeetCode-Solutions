class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0)    return 0;
        int m = dungeon.size(), n = dungeon[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        dp[m - 1][n - 1] = 1 - dungeon[m - 1][n - 1] >= 1 ? 1 - dungeon[m - 1][n - 1] : 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1)    continue;
                
                int from_right = 0, from_down = 0;
                if (j + 1 >= n)    from_right = INT_MAX;
                else    from_right = dp[i][j + 1] - dungeon[i][j] >= 1 ? dp[i][j + 1] - dungeon[i][j] : 1;
                
                if (i + 1 >= m)    from_down = INT_MAX;
                else    from_down = dp[i + 1][j] - dungeon[i][j] >= 1 ? dp[i + 1][j] - dungeon[i][j] : 1;
                
                dp[i][j] = min(from_down, from_right);
            }
        }
        
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[0][0];
    }
};