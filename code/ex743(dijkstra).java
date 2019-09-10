// Dijkstra

class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        int n = times.length;
        
        int[] time = new int[N + 1];    Arrays.fill(time, Integer.MAX_VALUE);    time[K] = 0;
        boolean[] visited = new boolean[N + 1];    // Store if the edge has been visited
        
        // Run dijkstra's algorithms to reach every node
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b)->time[a] - time[b]);
        pq.offer(K);
        
        while (!pq.isEmpty()) {
            int out = pq.poll();
            
            // Visit all edges out of current node
            for (int i = 0; i < n; i++) {
                if (times[i][0] != out || visited[times[i][1]])    continue;      
                
                if (time[out] + times[i][2] < time[times[i][1]]) {
                    time[times[i][1]] = time[out] + times[i][2];
                    if (pq.contains(times[i][1]))    pq.remove(times[i][1]);
                }
                
                if (!pq.contains(times[i][1]))    pq.offer(times[i][1]);
            }
            
            visited[out] = true;
        }
        
        // Get result
        int max = Integer.MIN_VALUE;
        for (int i = 1; i <= N; i++) {
            if (time[i] == Integer.MAX_VALUE)    return -1;
            max = Math.max(max, time[i]);
        }
        
        return max;
    }
}