class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        // Get the current skyline view from top and left
        int[] top = new int[n], left = new int[m];
        for (int i = 0; i < m; i++) {
            int max = Integer.MIN_VALUE;
            for (int j = 0; j < n; j++) {
                max = Math.max(max, grid[i][j]);
            }
            left[i] = max;
        }
        for (int i = 0; i < n; i++) {
            int max = Integer.MIN_VALUE;
            for (int j = 0; j < m; j++) {
                max = Math.max(max, grid[j][i]);
            }
            top[i] = max;
        }
        
        // Get the maximum increase each grid can make        
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res += Math.min(top[j], left[i]) - grid[i][j];
            }
        }
        
        return res;
    }
}