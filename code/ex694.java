class Solution {
    public Set<Integer> shape;
    public int m = 0, n = 0;
    
    public int numDistinctIslands(int[][] grid) {
        m = grid.length;    if (m == 0)    return 0;
        n = grid[0].length;    if (n == 0)    return 0;
        
        int cnt = 0;
        boolean[][] visited = new boolean[m][n];
        Set<Set<Integer>> shapes = new HashSet<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    shape = new HashSet<Integer>();    // Init shape set
                    dfs(grid, visited, i, j, i, j);    // Run dfs
                    // Judge if the shape duplicates with other islands. If not, cnt++
                    if (!shapes.contains(shape)) {
                        cnt++;
                        shapes.add(shape);
                    }
                }       
            }
        }
        
        return cnt;
    }
    
    private void dfs(int[][] grid, boolean[][] visited, int i, int j, int oi, int oj) {
        visited[i][j] = true;
        
        // Add the related coordinate to shape set, save as a unique index
        shape.add((i - oi) * 11 + (j - oj) * 10);
        
        // Go to next grid if possible
        // Go left
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 1)    dfs(grid, visited, i, j - 1, oi, oj);
        // Go right
        if (j + 1 < n && !visited[i][j + 1] && grid[i][j + 1] == 1)    dfs(grid, visited, i, j + 1, oi, oj);
        // Go down
        if (i + 1 < m && !visited[i + 1][j] && grid[i + 1][j] == 1)    dfs(grid, visited, i + 1, j, oi, oj);
        // Go up
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 1)    dfs(grid, visited, i - 1, j, oi, oj);
    
    }
}