class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<double> dp(30000);
        for (int i = K; i <= N; i++)    dp[i] = 1.0;
        
        double sum = 0.0;
        for (int i = K; i < K + W; i++)    sum += dp[i];
        if (K < 1)    return 0 <= N ? 1.0 : 0.0;
        dp[K - 1] = sum / W;
        
        // Sliding window
        for (int i = K - 2; i >= 0; i--) {
            sum += dp[i + 1] - dp[i + 1 + W];
            dp[i] = sum / W;
        }
        return dp[0];
    }
};