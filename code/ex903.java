class Solution {
    public int numPermsDISequence(String S) {
        int mod = (int)(1e9 + 7);
        int n = S.length();
        int[][] dp = new int[n + 1][n + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= i; j++) {
                if (S.charAt(i - 1) == 'D') {
                    for (int k = j; k < i; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
                else if (S.charAt(i - 1) == 'I') {
                    for (int k = 0; k < j; k++) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            }
        }
        
        int cnt = 0;
        for (int a : dp[n]) {
            cnt = (cnt + a) % mod;
        }
        return cnt;
    }
}