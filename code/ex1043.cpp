// DP

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            int m = 0;
            for (int j = 1; j <= K && i - j + 1 >= 0; j++) {
                m = max(m, A[i - j + 1]);
                if (i - j >= 0)
                    dp[i] = max(dp[i], m * j + dp[i - j]);
                else
                    dp[i] = max(dp[i], m * j);
            }
        }
        return dp[n - 1];
    }
};