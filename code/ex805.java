// Knapsack

class Solution {
    public boolean splitArraySameAverage(int[] A) {
        int N = A.length;
        int S = 0;
        for (int a : A)    S += a;
        double avg = (double)S / N;
        
        boolean[][] dp = new boolean[N + 1][S + 1];
        dp[0][0] = true;
        
        for (int a : A) {
            for (int n = N; n >= 1; n--) {
                for (int s = S; s >= 0; s--) {
                    if (s - a >= 0 && dp[n - 1][s - a]) {
                        dp[n][s] = true;

                        if (n != N && (double)s / n == avg)
                            return true;
                    }
                }
            }
        }
        
        return false;
    }
}