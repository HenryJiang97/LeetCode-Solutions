class Solution {
    public int cherryPickup(int[][] grid) {
        int n = grid.length;
        int result = cherry(grid, n, 0, 0, 0, 0, new int[n][n][n][n]);
        return result < 0 ? 0 : result;
    }
    
    // Calculate the most cherries can get when one person start at (x1, y1) and another at (x2, y2)
    private int cherry(int[][] grid, int n, int x1, int y1, int x2, int y2, int[][][][] memo) {
        int cherries = 0;
        // Out of bound or meet the obstacle
        if (x1 >= n || x2 >= n || y1 >= n || y2 >= n || grid[x1][y1] == -1 || grid[x2][y2] == -1)
            return Integer.MIN_VALUE;
        
        // Get memo
        if (memo[x1][y1][x2][y2] != 0)    return memo[x1][y1][x2][y2];
        
        // When first person reach the destination
        if (x1 == n - 1 && y1 == n - 1)
            return grid[x1][y1];
    
        // When second person reach the destination
        if (x2 == n - 1 && y2 == n - 1)
            return grid[x2][y2];
        
        // When two person meets at the same position
        if (x1 == x2 && y1 == y2)
            cherries = grid[x1][y1];
        else
            cherries = grid[x1][y1] + grid[x2][y2];
        
        // Recurrsion to get the max cherries start from (x1, y1) and (x2, y2)
        cherries += Math.max(Math.max(cherry(grid, n, x1 + 1, y1, x2 + 1, y2, memo), cherry(grid, n, x1 + 1, y1, x2, y2 + 1, memo)), Math.max(cherry(grid, n, x1, y1 + 1, x2 + 1, y2, memo), cherry(grid, n, x1, y1 + 1, x2, y2 + 1, memo)));
        
        // Save result to memo
        memo[x1][y1][x2][y2] = cherries;
        
        return cherries;
    }
}