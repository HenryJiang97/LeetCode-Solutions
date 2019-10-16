// DP

class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int cnt = 0;
        
        // Define and initialize the dp array
        boolean[][] dp = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            cnt++;
            dp[i][i] = true;
        }
        
        // Build dp array
        for (int l = 2; l <= n; l++) {
            for (int lo = 0; lo <= n - l; lo++) {
                int hi = lo + l - 1;
                if (s.charAt(lo) == s.charAt(hi)) {
                    if (dp[lo + 1][hi - 1] || lo + 1 >= hi - 1) {
                        cnt++;
                        dp[lo][hi] = true;
                    }
                }
            }
        }
        
        return cnt;
    }
}