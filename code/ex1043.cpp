class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            int MAX = 0;
            for (int j = i; j >= max(0, i - K + 1); j--) {
                MAX = max(MAX, A[j]);
                dp[i] = max(dp[i], MAX * (i - j + 1) + (j > 0 ? dp[j - 1] : 0));
            }
        }
        return dp[n - 1];
    }
};