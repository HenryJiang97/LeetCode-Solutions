// BFS, store the visited nodes at current state to a binary number.

class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;    if (n == 1)    return 0;
        
        boolean[][] visited = new boolean[n][1<<n];
        
        // Run BFS to find the shortest path
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            queue.offer(new int[]{i, 1 << i});
            visited[i][1 << i] = true;
        }
        
        int level = 0;
        while (!queue.isEmpty()) {
            
            for (int z = queue.size(); z > 0; --z) {    // Traverse current layer
                int[] out = queue.poll();
                int curr = out[0], currVisited = out[1];
                
                for (int next : graph[curr]) {
                    int nextVisited = currVisited | (1 << next);
                    if (visited[next][nextVisited])    continue;
                    
                    if (nextVisited == (1 << n) - 1)    return level + 1;
                    
                    queue.offer(new int[]{next, nextVisited});
                    visited[next][nextVisited] = true;
                }
            }
            
            level++;
        }
        
        return level;
    }
}