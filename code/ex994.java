class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        Queue<int[]> queue = new LinkedList<>();
        boolean[][] visited = new boolean[m][n];
        int left = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    visited[i][j] = true;
                    queue.offer(new int[]{i, j});
                }
                else if (grid[i][j] == 1)    left++;
            }
        }
        if (left == 0)    return 0;
        
        // Go BFS
        int minute = 0;
        int[][] dir = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; z--) {
                int[] out = queue.poll();
                int i = out[0], j = out[1];
                
                for (int d = 0; d < 4; d++) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    continue;
                    
                    if (grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                        visited[ni][nj] = true;
                        if (--left == 0)    return minute + 1;
                        queue.offer(new int[]{ni, nj});
                    }
                }
            }
            minute++;
        }
        
        return -1;
    }
}