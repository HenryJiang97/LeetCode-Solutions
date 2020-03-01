class Solution {
    public int findMaxForm(String[] strs, int M, int N) {
        int n = strs.length;
        
        int[][] dp = new int[M + 1][N + 1];
        for (int i = 1; i <= n; i++) {
            // Get zeros and ones in current string
            int zeros = 0, ones = 0;
            for (char c : strs[i - 1].toCharArray()) {
                if (c == '0')    zeros++;
                else    ones++;
            }
            
            // Knapsack
            for (int z = M; z >= zeros; z--) {
                for (int o = N; o >= ones; o--) {
                    dp[z][o] = Math.max(dp[z][o], dp[z - zeros][o - ones] + 1);
                }
            }
        }
        
        return dp[M][N];
    }
}