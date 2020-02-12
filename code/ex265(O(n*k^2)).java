// O(n*k^2)

class Solution {
    public int minCostII(int[][] costs) {
        int n = costs.length;    if (n == 0)    return 0;
        int k = costs[0].length;
        
        int[][] dp = new int[n][k];
        for (int j = 0; j < k; j++)    dp[0][j] = costs[0][j];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < k; j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for (int z = 0; z < k; z++) {
                    if (j == z)    continue;
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][z] + costs[i][j]);
                }
            }
        }
        
        int min = Integer.MAX_VALUE;
        for (int j = 0; j < k; j++)    min = Math.min(min, dp[n - 1][j]);
        
        return min;
    }
}