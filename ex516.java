// Recurrsive DP using memo
// Recurrsion: if (s[i] == s[j])    dp[i][j] = dp[i + 1][j - 1] + 2
//             else    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])

class Solution {
    public int longestPalindromeSubseq(String s) {
        return recurrsion(s, new int[s.length()][s.length()], 0, s.length() - 1);
    }
    
    private int recurrsion(String s, int[][] dp, int i, int j) {
        if (i == j)    return 1;
        else if (i > j)    return 0;
        
        // Load memo
        if (dp[i][j] != 0)    return dp[i][j];
        
        // Recurrsion
        int p = 0;
        if (s.charAt(i) == s.charAt(j))
            p = recurrsion(s, dp, i + 1, j - 1) + 2;
        else
            p = Math.max(recurrsion(s, dp, i + 1, j), recurrsion(s, dp, i, j - 1));
        
        // Save to memo
        dp[i][j] = p;       
        return p;
    }
}