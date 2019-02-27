class Solution {
    private int count = 0;
    private int[][] visited;
    
    private void DFS(int[][] grid, int i, int j) {
        count++;
        visited[i][j] = 1;
        int row = grid.length;
        int col = grid[0].length;
        
        // Go right
        if (j + 1 < col && grid[i][j + 1] == 1 && visited[i][j + 1] == 0)    DFS(grid, i, j + 1);
        // Go left
        if (j - 1 >= 0 && grid[i][j - 1] == 1 && visited[i][j - 1] == 0)    DFS(grid, i, j - 1);
        // Go up
        if (i - 1 >= 0 && grid[i - 1][j] == 1 && visited[i - 1][j] == 0)    DFS(grid, i - 1, j);
        // Go down
        if (i + 1 < row && grid[i + 1][j] == 1 && visited[i + 1][j] == 0)    DFS(grid, i + 1, j);
    }
    
    
    public int maxAreaOfIsland(int[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        
        visited = new int[row][col];
        int max = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    count = 1;
                    visited[i][j] = 1;
                    // Go right
                    if (j + 1 < col && grid[i][j + 1] == 1 && visited[i][j + 1] == 0)    DFS(grid, i, j + 1);
                    // Go left
                    if (j - 1 >= 0 && grid[i][j - 1] == 1 && visited[i][j - 1] == 0)    DFS(grid, i, j - 1);
                    // Go up
                    if (i - 1 >= 0 && grid[i - 1][j] == 1 && visited[i - 1][j] == 0)    DFS(grid, i - 1, j);
                    // Go down
                    if (i + 1 < row && grid[i + 1][j] == 1 && visited[i + 1][j] == 0)    DFS(grid, i + 1, j);
                    
                    max = Math.max(max, count);
                }
            }
        }
        return max;
    }
}