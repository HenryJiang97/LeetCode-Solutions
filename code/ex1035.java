// 2D-DP: dp[a][b] => the maximum number of connecting lines in subarray A[a : ], B[b : ]

class Solution {
    public int maxUncrossedLines(int[] A, int[] B) {
        int na = A.length, nb = B.length;
        
        int[][] dp = new int[na + 1][nb + 1];
        
        for (int a = na - 1; a >= 0; a--) {
            for (int b = nb - 1; b >= 0; b--) {
                if (A[a] == B[b])    dp[a][b] = dp[a + 1][b + 1] + 1;
                else    dp[a][b] = Math.max(dp[a + 1][b], dp[a][b + 1]);
            }
        }
        
        return dp[0][0];
    }
}