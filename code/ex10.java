// DP
// s[i] == 'a' && p[j] == 'a': dp[i][j] = dp[i - 1][j - 1]
// p[j] == '.': dp[i][j] = dp[i - 1][j - 1]
// p[i] == '*': dp[i][j] = dp[i][j - 2] (repete char before zero time)
//                      || dp[i - 1][j] (if p[j - 1] == s[i] || p[j - 1] == '.')

class Solution {
    public boolean isMatch(String s, String p) {
        char[] S = s.toCharArray(), P = p.toCharArray();
        int ns = S.length, np = P.length;
         
        // Init dp array
        boolean[][] dp = new boolean[ns + 1][np + 1];
        dp[0][0] = true;
        
        for (int j = 2; j <= np; j++) {    // If s is empty string
            if (P[j - 1] == '*') {    // If current position is '*'
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Build dp array
        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= np; ++j) {
                if (S[i - 1] == P[j - 1] || P[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                
                if (P[j - 1] == '*') {
                    dp[i][j] |= dp[i][j - 2];
                    
                    if (j >= 2 && (P[j - 2] == S[i - 1] || P[j - 2] == '.'))
                        dp[i][j] |= dp[i - 1][j];
                }
            }
        }   
        
        return dp[ns][np];
    }
}