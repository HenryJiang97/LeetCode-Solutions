class Solution {
    public final int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public void wallsAndGates(int[][] rooms) {
        int m = rooms.length;    if (m == 0)    return;
        int n = rooms[0].length;    if (n == 0)    return;
        
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rooms[i][j] == 0)
                    queue.offer(new int[]{i, j});
        
        int dis = 0;
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; z--) {
                int[] out = queue.poll();
                int i = out[0], j = out[1];
                for (int[] d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || rooms[ni][nj] != Integer.MAX_VALUE)
                        continue;
                    rooms[ni][nj] = dis + 1;
                    queue.offer(new int[]{ni, nj});
                }
            }
            dis++;
        }
    }
}   