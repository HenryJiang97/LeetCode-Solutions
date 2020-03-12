class Solution {
    public int numWays(int n, int k) {
        if (n == 0)    return 0;
        if (n == 1)    return k;
        
        int dp1 = k * k, dp11 = k;
        for (int i = 2; i < n; i++) {
            int cur = (k - 1) * (dp1 + dp11);
            dp11 = dp1;
            dp1 = cur;
        }
        
        return dp1;
    }
}