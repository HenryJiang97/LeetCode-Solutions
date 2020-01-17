class Solution {
    private int m, n;
    private final int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int shortestBridge(int[][] A) {
        m = A.length;    n = A[0].length;
        
        boolean[][] visited = new boolean[m][n];
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            boolean sign = false;
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0)    continue;
                getFirstIsland(A, visited, queue, i, j);
                sign = true;
                break;
            }
            if (sign)    break;
        }
        
        // Run BFS to find the shortest path from island 1 to island 2
        int step = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int z = size; z > 0; z--) {
                int[] out = queue.poll();
                int i = out[0], j = out[1];
                for (int[] d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    continue;
                    if (A[ni][nj] == 1)    return step;
                    visited[ni][nj] = true;
                    queue.offer(new int[]{ni, nj});
                }
            }
            step++;
        }
        
        return -1;
    }
    
    // DFS to push all grids of island 1 to the queue
    private void getFirstIsland(int[][] A, boolean[][] visited, Queue<int[]> queue, int i, int j) {
        queue.offer(new int[]{i, j});
        visited[i][j] = true;
        for (int[] d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= m || A[ni][nj] != 1 || visited[ni][nj])    continue;
            getFirstIsland(A, visited, queue, ni, nj);
        }
    }
}