class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + A[i - 1];
        
        vector<double> dp(n, DBL_MIN);
        for (int i = 0; i < n; i++)    dp[i] = (double)prefix[i + 1] / (i + 1);
        for (int k = 2; k <= K; k++) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    dp[i] = max(dp[i], dp[j] + (double)(prefix[i + 1] - prefix[j + 1]) / (i - j));
                }
            }
        }
        
        return dp[n - 1];
    }
};