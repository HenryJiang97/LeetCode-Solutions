// DP without inplace

class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)    continue;
                int curr = grid[i][j];
                grid[i][j] = Integer.MAX_VALUE / 2;
                if (i - 1 >= 0)    grid[i][j] = Math.min(grid[i][j], grid[i - 1][j] + curr);
                if (j - 1 >= 0)    grid[i][j] = Math.min(grid[i][j], grid[i][j - 1] + curr);
            }
        }
        
        return grid[m - 1][n - 1];
    }
}