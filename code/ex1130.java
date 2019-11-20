// DP, dp[i][j] => The minimum cost between i and j

class Solution {
    public int mctFromLeafValues(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];
        int[][] max = new int[n][n];
        for (int i = 0; i < n; i++)
            max[i][i] = arr[i];

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + max[i][k] * max[k + 1][j]);
                }
                max[i][j] = Math.max(max[i][j - 1], arr[j]);
            }
        }
        
        return dp[0][n - 1];
    }
}