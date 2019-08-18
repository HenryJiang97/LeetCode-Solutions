class Solution {
    public int m, n;
    
    public int numIslands(char[][] grid) {
        m = grid.length;    if (m == 0)    return 0;
        n = grid[0].length;    if (n == 0)    return 0;
        
        int cnt = 0;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] || grid[i][j] == '0')    continue;
                cnt++;
                dfs(grid, i, j, visited);
            }
        }
        
        return cnt;
    }
    
    private void dfs(char[][] grid, int i, int j, boolean[][] visited) {
        visited[i][j] = true;
        
        // Go four directions
        // Go right
        if (j + 1 < n && !visited[i][j + 1] && grid[i][j + 1] == '1')
            dfs(grid, i, j + 1, visited);
        
        // Go down
        if (i + 1 < m && !visited[i + 1][j] && grid[i + 1][j] == '1')
            dfs(grid, i + 1, j, visited);
        
        // Go up
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == '1')
            dfs(grid, i - 1, j, visited);
        
        // Go left
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == '1')
            dfs(grid, i, j - 1, visited);
    }
}