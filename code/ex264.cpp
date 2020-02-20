class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);    dp[0] = 1;
        for (int i = 1, p2 = 0, p3 = 0, p5 = 0; i < n; i++) {
            dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
            if (dp[p2] * 2 == dp[i])    p2++;
            if (dp[p3] * 3 == dp[i])    p3++;
            if (dp[p5] * 5 == dp[i])    p5++;
        }
        return dp[n - 1];
    }
};