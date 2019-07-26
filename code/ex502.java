// Sort + Heap

class Solution {
    public int findMaximizedCapital(int k, int W, int[] Profits, int[] Capital) {
        int n = Profits.length;
        int[][] projects = new int[n][2];
        for (int i = 0; i < n; i++) {
            projects[i][0] = Profits[i];
            projects[i][1] = Capital[i];
        }
        // Sort the array by capital in ascending order
        Arrays.sort(projects, (a, b) -> a[1] - b[1]);
        
        // Priority queue by the profits in descending order
        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return b[0] - a[0];
            }
        });
        
        int cap = W, i = 0, cnt = 0;
        while (cnt < k) {
            while (i < n && projects[i][1] <= cap)
                pq.offer(projects[i++]);
            
            if (pq.isEmpty())    break;
            else {
                cap += pq.poll()[0];
                cnt++;
            }
        }
        
        return cap;
    }
}