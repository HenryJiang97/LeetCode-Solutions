// BFS

class Solution {
    public int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    public int cutOffTree(List<List<Integer>> forest) {
        int m = forest.size();    if (m == 0)    return 0;
        int n = forest.get(0).size();    if (n == 0)    return 0;
        
        // Store the coordinate of trees in ascending order of height
        TreeMap<Integer, int[]> map = new TreeMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest.get(i).get(j) > 1) {
                    map.put(forest.get(i).get(j), new int[]{i, j});
                }
            }
        }
        
        // Run BFS to find the shorest path;
        Iterator<Map.Entry<Integer, int[]>> it = map.entrySet().iterator();
        
        int step = 0;
        int[] start = new int[]{0, 0};
        int[] dest = new int[]{0, 0};
        while (it.hasNext()) {
            dest = it.next().getValue();
            
            int s = bfs(start, dest, m, n, forest);
            if (s == -1)    return -1;
            else    step += s;
            
            start = dest;
        }
        
        return step;
    }
    
    // BFS to find the shortest path from start point to destination
    private int bfs(int[] start, int[] dest, int m, int n, List<List<Integer>> forest) {
        boolean[][] visited = new boolean[m][n];
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(start);    visited[start[0]][start[1]] = true;
        
        int step = 0;
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; --z) {
                int[] out = queue.poll();
                
                if (out[0] == dest[0] && out[1] == dest[1]) {
                    return step;
                }
                
                // Go four directions
                for (int a = 0; a < 4; a++) {
                    int i = out[0] + dir[a][0], j = out[1] + dir[a][1];
                    if (i < 0 || i >= m || j < 0 || j >= n)    continue;    // Out of bound exception
                    if (forest.get(i).get(j) == 0)    continue;    // Meets obstacles
                    if (!visited[i][j])    queue.offer(new int[]{i, j});
                    visited[i][j] = true;
                }
            }
            step++;
        }
        
        return -1;
    }
}