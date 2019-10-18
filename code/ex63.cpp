class Solution {
    int m, n;
    vector<vector<int>> dir = {{1, 0}, {0, 1}};
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m = grid.size();    if (m == 0)    return 0;
        n = grid[0].size();    if (n == 0)    return 0;
        
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(grid, memo, 0, 0);
    }
    
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& memo, int i, int j) {
        if (i == m - 1 && j == n - 1 && grid[m - 1][n - 1] == 0)    return 1;
        if (grid[i][j] == 1)    return 0;
        
        if (memo[i][j] != -1)    return memo[i][j];
        
        int cnt = 0;
        for (int d = 0; d < 2; d++) {
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if (ni >= m || nj >= n)    continue;
            cnt += dfs(grid, memo, ni, nj);
        }
        
        memo[i][j] = cnt;
        return cnt;
    }
};