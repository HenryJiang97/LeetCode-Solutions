class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int[] dp = new int[A.length];
        
        for (int i = 0; i < A.length; i++) {
            dp[i] = i + A[i];
        }
        
        int max = Integer.MIN_VALUE;
        int m = dp[0];
        for (int i = 1; i < A.length; i++) {
            max = Math.max(max, m + A[i] - i);
            m = Math.max(m, dp[i]);
        }
        
        return max;
    }
}