class Solution {
    public final int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int shortestDistance(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        
        int[][] dis = new int[m][n];    // Total distance of the shortest distance to every building
        int[][] reach = new int[m][n];    // Total amount of buildings which can reach current point
        int buildingCnt = 0;
        
        // Run bfs for each building
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 1)    continue;
                buildingCnt++;
                
                boolean[][] visited = new boolean[m][n];
                Queue<int[]> queue = new LinkedList<>();
                queue.offer(new int[]{i, j});
                visited[i][j] = true;
                int d = 0;
                
                while (!queue.isEmpty()) {
                    for (int z = queue.size(); z > 0; z--) {
                        int[] out = queue.poll();
                        int ci = out[0], cj = out[1];
                        dis[ci][cj] += d;
                        reach[ci][cj]++;
                        
                        for (int[] di : dir) {
                            int ni = ci + di[0], nj = cj + di[1];
                            if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] != 0 || visited[ni][nj])
                                continue;
                            visited[ni][nj] = true;
                            queue.offer(new int[]{ni, nj});
                        }
                    }
                    d++;
                }
            }
        }
        
        // Get result
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)    continue;
                if (reach[i][j] == buildingCnt)
                    min = Math.min(min, dis[i][j]);
            }
        }
        
        return min == Integer.MAX_VALUE ? -1 : min;
    }
}