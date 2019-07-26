// Heap

class Solution {
    public int[][] kClosest(int[][] points, int K) {
        int n = points.length;
        
        double[] distance = new double[n];
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> (a[0] < b[0]) ? -1 : 1);
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            pq.offer(new double[]{Math.sqrt(x * x + y * y), (double)i});
        }
        
        int[][] res = new int[K][2];
        int i = 0;
        while (i < K) {
            res[i++] = points[(int)(pq.poll()[1])];
        }
        
        return res;
    }
}