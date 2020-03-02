// Knapsack

class Solution {
    public boolean splitArraySameAverage(int[] A) {
        int n = A.length;
        int sum = 0;
        for (int a : A)    sum += a;
        double avg = (double)sum / n;
        
        boolean[][] dp = new boolean[n + 1][sum + 1];
        dp[0][0] = true;
        
        for (int a : A) {
            for (int i = n; i >= 1; i--) {
                for (int s = sum; s >= a; s--) {
                    if (dp[i - 1][s - a]) {
                        dp[i][s] = true;
                        if (i < n && (double)s / i == avg)
                            return true;
                    }
                }
            }
        }
        
        return false;
    }
}