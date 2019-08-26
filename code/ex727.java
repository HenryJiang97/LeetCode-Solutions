class Solution {
    public String minWindow(String S, String T) {
        S = " " + S;    T = " " + T;
        int ns = S.length(), nt = T.length();
        
        // Define and init dp array
        int[][] dp = new int[ns][nt];
        for (int i = 0; i < ns; i++) {
            for (int j = 0; j < nt; j++) {
                if (j == 0)    dp[i][j] = 0;
                else    dp[i][j] = Integer.MAX_VALUE / 2;
            }
        }
        
        // Build dp array
        for (int j = 1; j < nt; j++) {
            for (int i = 1; i < ns; i++) {
                if (S.charAt(i) == T.charAt(j)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        
        // Find the minimum length of substring
        int min_len = Integer.MAX_VALUE;
        for (int i = 0; i < ns; i++) {
            min_len = Math.min(min_len, dp[i][nt - 1]);
        }
        
        if (min_len >= Integer.MAX_VALUE / 2)    return "";
        
        // Get the end point of the shortest substring
        int index = 0;
        for (int i = 1; i < ns; i++) {
            if (min_len == dp[i][nt - 1]) {
                index = i;
                break;
            }
        }
        
        return S.substring(index - min_len + 1, index + 1);
    }
}