// Deque with increasing sequence

class Solution {
    public int shortestSubarray(int[] A, int K) {
        int n = A.length;
        int min = Integer.MAX_VALUE;
        
        // Build prefix sum array
        int[] prefix = new int[n + 1];
        for (int i = 1; i < n + 1; i++)    prefix[i] = prefix[i - 1] + A[i - 1];
        
        // Build deque
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 0; i < n + 1; i++) {
            // Remove the decreasing sequence
            while (!deque.isEmpty() && prefix[i] <= prefix[deque.peekLast()])
                deque.pollLast();
            
            // Remove head until sum < K
            while (!deque.isEmpty() && prefix[i] - prefix[deque.peekFirst()] >= K)
                min = Math.min(min, i - deque.poll());
                
            deque.offer(i);
        }
        
        return min == Integer.MAX_VALUE ? -1 : min;
    }
}