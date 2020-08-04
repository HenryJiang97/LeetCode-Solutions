class Solution {
    const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m, n;
    
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        m = grid.size();    n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[r0][c0] = 1;
        dfs(grid, visited, r0, c0, grid[r0][c0]);      
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] < 0)
                    grid[i][j] = color;
        
        return grid;
    }
    
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int group) {
        if (onBoundary(grid, i, j, group))    grid[i][j] = -grid[i][j];
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj] || grid[ni][nj] != group)    continue;
            visited[ni][nj] = 1;
            dfs(grid, visited, ni, nj, group);
        }
    }
    
    bool onBoundary(vector<vector<int>>& grid, int i, int j, int target) {
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || (grid[ni][nj] > 0 && grid[ni][nj] != target))
                return 1;
        }
        return 0;
    }
};