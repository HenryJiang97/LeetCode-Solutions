// DP
// dp[i] = (dp[i + 1] + dp[i + 2] + ... + dp[K - 1]) * (1 / W) + (1 / W) * rest points valid getting result larger than K - 1.

class Solution {
    public double new21Game(int N, int K, int W) {
        // Corner cases
        if (K == 0)    return 1.0;
        
        // Build dp array
        double[] dp = new double[K];
        
        double store = 0.0;
        for (int k = K - 1; k >= 0; --k) {
            dp[k] += ((double)store / W);  
            
            if (k >= N - W)
                dp[k] += ((double)(N - K + 1) / W);
            else if (k >= K - W)
                dp[k] += ((double)(k + W - K + 1) / W);
            
            // Update store
            store += dp[k];
            if (k < K - W)    store -= dp[k + W];
        }
        
        return dp[0];
    }
}