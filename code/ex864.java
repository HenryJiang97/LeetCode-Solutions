class Solution {
    public final int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int shortestPathAllKeys(String[] g) {
        int m = g.length, n = g[0].length();
        
        char[][] grid = new char[m][n];
        int start_i = 0, start_j = 0;
        int maxKeySet = 0;
        for (int i = 0; i < g.length; i++) {
            String line = g[i];
            char[] arr = line.toCharArray();
            grid[i] = arr;
            for (int j = 0; j < arr.length; j++) {
                if (arr[j] == '@') {
                    start_i = i;
                    start_j = j;
                }
                else if (arr[j] >= 'a' && arr[j] <= 'f')
                    maxKeySet |= (1 << (arr[j] - 'a'));
            }
        }
        
        // BFS
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{start_i, start_j, 0});
        boolean[][][] visited = new boolean[m][n][maxKeySet + 1];
        visited[start_i][start_j][0] = true;
        
        int moves = 0;
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; z--) {
                int[] out = queue.poll();
                int i = out[0], j = out[1], keySet = out[2];
                if (keySet == maxKeySet)    return moves;
                
                for (int[] d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == '#')
                        continue;
                    
                    if (grid[ni][nj] >= 'A' && grid[ni][nj] <= 'F' 
                        && (keySet & (1 << (grid[ni][nj] - 'A'))) == 0)
                        continue;
                    
                    int newKeySet = keySet;
                    if (grid[ni][nj] >= 'a' && grid[ni][nj] <= 'f')
                        newKeySet = keySet | (1 << (grid[ni][nj] - 'a'));
                    
                    if (visited[ni][nj][newKeySet])    continue;
                    queue.offer(new int[]{ni, nj, newKeySet});
                    visited[ni][nj][newKeySet] = true;
                }
            }
            moves++;
        }
        
        return -1;
    }
}