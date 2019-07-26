// DP

class Solution {
    public int minSwap(int[] A, int[] B) {
        // Create 2D dp array and init dp[0]
        // dp[i][0] refers to not swap A[i] with B[i], dp[i][1] refers to swap A[i] with B[i]
        int[][] dp = new int[A.length][2];
        dp[0][1] = 1;
        
        for (int i = 1; i < A.length; ++i) {
            // Test if increasing before swap A[i - 1] with B[i - 1]
            boolean selfIncreasing = A[i] > A[i - 1] && B[i] > B[i - 1];
            // Test if increasing after swap A[i - 1] with B[i - 1]
            boolean swapIncreasing = A[i] > B[i - 1] && B[i] > A[i - 1];
            
            if (selfIncreasing && swapIncreasing) {
                dp[i][0] = Math.min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = Math.min(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            } else if (selfIncreasing) {
                // Keep synchronized with item before
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1] + 1;
            } else if (swapIncreasing) {
                // Keep inversed with item before
                dp[i][0] = dp[i - 1][1];
                dp[i][1] = dp[i - 1][0] + 1;
            }
        }
        
        return Math.min(dp[A.length - 1][0], dp[A.length - 1][1]);
    }
}