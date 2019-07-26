class Solution {
    public int smallestRangeII(int[] A, int K) {
        int n = A.length;    if (n == 0)    return 0;
        Arrays.sort(A);

        // Find the boarder of add and minus, for A[0...i] add K, A[i + 1, n - 1] minus K
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < n - 1; i++)
            min = Math.min(min, Math.max(A[i] + K, A[n - 1] - K) - Math.min(A[0] + K, A[i + 1] - K));
        
        return Math.min(min, A[n - 1] - A[0]);
    }
}