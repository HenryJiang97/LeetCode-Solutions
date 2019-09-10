// BFS

class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        int n = times.length;
        
        int[] time = new int[N + 1];    Arrays.fill(time, Integer.MAX_VALUE);    time[K] = 0;
        
        // Run dijkstra's algorithms to reach every node
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{K, 0});
        
        while (!queue.isEmpty()) {
            int[] out = queue.poll();
            int curPoint = out[0], curTime = out[1];

            if (curTime > time[curPoint])    continue;    // If current arriving time at certain point is longer than the earliest time, skip, otherwise, its out edges should be traversed again to update.
            
            // Visit all edges out of current node
            for (int i = 0; i < n; i++) {
                if (times[i][0] != curPoint)    continue;     
                int nextPoint = times[i][1], nextTime = times[i][2];

                if (time[curPoint] + nextTime < time[nextPoint]) {
                    time[nextPoint] = time[curPoint] + nextTime;
                    queue.offer(new int[]{nextPoint, time[nextPoint]});
                }
            }
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