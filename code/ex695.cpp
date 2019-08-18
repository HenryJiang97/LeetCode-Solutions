// DFS

class Solution {
    int m, n;
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();    if (m == 0)    return 0;
        n = grid[0].size();    if (n == 0)    return 0;
        
        int MAX = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)    continue;
                MAX = max(MAX, dfs(grid, visited, i, j));
            }
        }
        
        return MAX;
    }
    
private:
    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        
        int cnt = 1;
        // Go right
        if (j + 1 < n && !visited[i][j + 1] && grid[i][j + 1] == 1)
            cnt += dfs(grid, visited, i, j + 1);
        
        // Go down
        if (i + 1 < m && !visited[i + 1][j] && grid[i + 1][j] == 1)
            cnt += dfs(grid, visited, i + 1, j);
        
        // Go left
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1)
            cnt += dfs(grid, visited, i, j - 1);
        
        // Go up
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1)
            cnt += dfs(grid, visited, i - 1, j);
    
        return cnt;
    }
};