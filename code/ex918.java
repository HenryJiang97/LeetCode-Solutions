class Solution {
    public int maxSubarraySumCircular(int[] A) {
        int total = 0, maxSum = 0, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE, minSum = 0;
        for (int a : A) {
            total += a;
            maxSum = Math.max(maxSum + a, a);
            minSum = Math.min(minSum + a, a);
            max = Math.max(max, maxSum);
            min = Math.min(min, minSum);
        }
        return max > 0 ? Math.max(max, total - min) : max;
    }
}