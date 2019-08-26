// BFS

class Solution {
    public int numBusesToDestination(int[][] routes, int S, int T) {
        if (S == T)    return 0;
        int n = routes.length;
        
        // Save bus routes to an list
        List<Set<Integer>> buses = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Set<Integer> bus = new HashSet<>();
            for (int j = 0; j < routes[i].length; j++) {
                bus.add(routes[i][j]);
            }
            buses.add(bus);
        }
        
        // Run BFS search
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        queue.add(S);
        
        // Init queue
        for (int i = 0; i < n; i++) {
            if (buses.get(i).contains(S)) {
                visited[i] = true;
                for (int j = 0; j < routes[i].length; ++j) {
                    if (routes[i][j] == T)    return 1;
                    queue.add(routes[i][j]);
                }
            }
        }
        
        // BFS
        int cnt = 1;
        while (!queue.isEmpty()) {
            for (int z = queue.size() - 1; z >= 0; --z) {
                int out = queue.poll();
                
                // Add stops which can be reached by next bus to the queue
                for (int i = 0; i < n; i++) {
                    if (!visited[i] && buses.get(i).contains(out)) {
                        visited[i] = true;
                        
                        for (int j = 0; j < routes[i].length; j++) {
                            if (routes[i][j] == T)    return cnt + 1;
                            queue.add(routes[i][j]);
                        }
                    }
                }
            }
            cnt++;
        }
        
        
        return -1;
    }
}