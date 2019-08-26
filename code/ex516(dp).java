// 2D-DP

class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();    if (n == 0)    return 0;
        
        // Define dp array
        int[][] dp = new int[n][n];
        // Init dp array
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        
        // Build dp array
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s.charAt(i) == s.charAt(j)) {    // "aba"
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else {    // "abb"
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
}