class Solution {
    public int integerBreak(int n) {
        int[] dp = new int[n + 1];
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i] = Math.max(dp[i], j * dp[i - j]);
                dp[i] = Math.max(dp[i], j * (i - j));
            }
        }   
        
        return dp[n];
    }
}