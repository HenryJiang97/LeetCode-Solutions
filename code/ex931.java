class Solution {
    public int minFallingPathSum(int[][] A) {
        int m = A.length, n = A[0].length;
        
        // Define an dp array
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++)    Arrays.fill(dp[i], Integer.MAX_VALUE);
        for (int j = 0; j < n; j++)    dp[0][j] = A[0][j];
        
        // Build dp array
        for (int i = 1; i < m; i++) {
            dp[i][0] = Math.min(dp[i][0], Math.min(dp[i - 1][0], n > 1 ? dp[i - 1][1] : Integer.MAX_VALUE) + A[i][0]);
            for (int j = 1; j < n - 1; j++) {
                dp[i][j] = Math.min(dp[i][j], Math.min(dp[i - 1][j], Math.min(dp[i - 1][j - 1], dp[i - 1][j + 1])) + A[i][j]);
            }
            dp[i][n - 1] = Math.min(dp[i][n - 1], Math.min(dp[i - 1][n - 1], n - 2 >= 0 ? dp[i - 1][n - 2] : Integer.MAX_VALUE) + A[i][n - 1]);
        }
        
        // Get result
        int minSum = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++)
            minSum = Math.min(minSum, dp[m - 1][j]);
        
        return minSum;
    }
}