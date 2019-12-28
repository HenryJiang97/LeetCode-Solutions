class Solution {
    public boolean isMatch(String s, String p) {
        int n1 = s.length(), n2 = p.length();
        
        boolean[][] dp = new boolean[n1 + 1][n2 + 1];
        dp[0][0] = true;
        for (int i2 = 1; i2 <= n2; i2++)
            if (p.charAt(i2 - 1) == '*')
                dp[0][i2] = true;
            else
                break;
        
        for (int i1 = 1; i1 <= n1; i1++) {
            for (int i2 = 1; i2 <= n2; i2++) {
                if (p.charAt(i2 - 1) == '*') {
                    dp[i1][i2] = dp[i1 - 1][i2] || dp[i1][i2 - 1];
                }
                else {
                    dp[i1][i2] = dp[i1 - 1][i2 - 1] && (p.charAt(i2 - 1) == '?' || s.charAt(i1 - 1) == p.charAt(i2 - 1));
                }
            }
        }
        
        return dp[n1][n2];
    }
}