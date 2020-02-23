class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int m = dungeon.length, n = dungeon[0].length;
        int[][] dp = new int[m][n];
        dp[m - 1][n - 1] = Math.max(1, 1 - dungeon[m - 1][n - 1]);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1)    continue;
                dp[i][j] = Integer.MAX_VALUE;
                if (i + 1 < m)    dp[i][j] = Math.min(dp[i][j], dp[i + 1][j] - dungeon[i][j]);
                if (j + 1 < n)    dp[i][j] = Math.min(dp[i][j], dp[i][j + 1] - dungeon[i][j]);
                dp[i][j] = Math.max(1, dp[i][j]);
            }
        }
        
        return Math.max(1, dp[0][0]);
    }
}