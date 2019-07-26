// DP

class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0)    return 0;
        
        int dp[][] = new int[matrix.length][matrix[0].length];
        int max = 0;
        
        // Base case
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][0] == '1')    {dp[i][0] = 1;    max = 1;}
        }
        for (int j = 0; j < matrix[0].length; j++) {
            if (matrix[0][j] == '1')    {dp[0][j] = 1;    max = 1;}
        }
        
        // DP case   
        for (int i = 1; i < matrix.length; i++) {
            for (int j = 1; j < matrix[0].length; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = Math.min(Math.min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    max = Math.max(max, dp[i][j]);
                }
            }
        }

        return (int)Math.pow(max, 2);
    }
}