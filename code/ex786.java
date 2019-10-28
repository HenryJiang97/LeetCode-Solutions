// Heap

class Solution {
    public int[] kthSmallestPrimeFraction(int[] A, int K) {
        int n = A.length;
        
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return A[a[0]] * A[b[1]] < A[a[1]] * A[b[0]] ? -1 : 1;
            }
        });
        
        for (int i = 1; i < n; i++)    pq.offer(new int[]{0, i});
        int cnt = 0;
        
        while (!pq.isEmpty()) {
            int[] out = pq.poll();
            int lo = out[0], hi = out[1];
            if (++cnt == K)    return new int[]{A[lo], A[hi]};
            
            if (lo + 1 < hi)    pq.offer(new int[]{lo + 1, hi});
        }
        
        return new int[]{};
    }
}