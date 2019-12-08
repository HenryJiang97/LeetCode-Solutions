class Solution {
    public int longestRepeatingSubstring(String S) {
        int n = S.length();
        int[][] dp = new int[n][n];
        int max = 0;
        // Init
        for (int j = 1; j < n; j++)
            if (S.charAt(j) == S.charAt(0)) {
                dp[0][j] = 1;
                max = 1;
            }
        // Build
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (S.charAt(i) == S.charAt(j)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    max = Math.max(max, dp[i][j]);
                }
        return max;
    }
}