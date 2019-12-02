class Solution {
    public final int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    
    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1)    return -1;
        int n = grid.length;
        
        boolean[][] visited = new boolean[n][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        visited[0][0] = true;
        
        int len = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int z = size; z > 0; z--) {
                int[] out = queue.poll();
                int i = out[0], j = out[1];
                if (i == n - 1 && j == n - 1)    return len;
                
                for (int[] d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= n || nj >= n || grid[ni][nj] == 1 || visited[ni][nj])
                        continue;
                    queue.offer(new int[]{ni, nj});
                    visited[ni][nj] = true;
                }
            }
            len++;
        }
        
        return -1;
    }
}