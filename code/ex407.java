// BFS

class Solution {
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length;     if (m == 0)    return 0;
        int n = heightMap[0].length;    if (n == 0)    return 0;
        
        boolean[][] visited = new boolean[m][n];
        // Save the height and coordinate of points from four edges to the heap
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b)->a[0] - b[0]);
        for (int i = 0; i < m; i++) {
            pq.offer(new int[]{heightMap[i][0], i, 0});
            pq.offer(new int[]{heightMap[i][n - 1], i, n - 1});
            visited[i][0] = true;    visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.offer(new int[]{heightMap[0][j], 0, j});
            pq.offer(new int[]{heightMap[m - 1][j], m - 1, j});
            visited[0][j] = true;    visited[m - 1][j] = true;
        }
        
        int res = 0;
        int[][] dir = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};    // Directions
        // Find the point with lowest height which serves as the water infusion point
        while (!pq.isEmpty()) {
            int[] infusion = pq.poll();
            int i = infusion[1], j = infusion[2], h = infusion[0];
            
            // Run BFS from point[ii, ij]
            Queue<int[]> queue = new LinkedList<>();
            queue.offer(new int[]{i, j});
            while (!queue.isEmpty()) {
                int[] out = queue.poll();
                
                // Go four directions from the starting point
                for (int c = 0; c < 4; c++) {
                    int i1 = out[0] + dir[c][0], j1 = out[1] + dir[c][1];
                    if (i1 < 0 || j1 < 0 || i1 >= m || j1 >= n)    continue;
                    
                    int h1 = heightMap[i1][j1];
                    
                    if (visited[i1][j1])    continue;
                    visited[i1][j1] = true;
                    
                    if (h1 < h) {    // Lower than the starting point
                        res += h - h1;
                        queue.offer(new int[]{i1, j1});
                    } else {
                        pq.offer(new int[]{h1, i1, j1});
                    }
                }
            }
        }
        
        return res;
    }
}