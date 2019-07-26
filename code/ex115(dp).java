// DP
// If char at a position matches, dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j]
// Else, dp[i + 1][j + 1] = dp[i + 1][j]

import java.util.Arrays;

class Solution {
    public int numDistinct(String s, String t) {
        // Define dp array
        int[][] dp = new int[t.length() + 1][s.length() + 1];
        
        // Init dp array
        Arrays.fill(dp[0], 1);
        
        // Bottom up dp
        for (int i = 0; i < t.length(); i++)
            for (int j = 0; j < s.length(); j++)
                if (s.charAt(j) == t.charAt(i))
                    dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
                else    dp[i + 1][j + 1] = dp[i + 1][j];

        
        
        return dp[t.length()][s.length()];
    }
}