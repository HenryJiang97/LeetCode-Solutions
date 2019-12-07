// DP
// Two situations:
// 1. Swap the first num with the ith num, dp[i] = dp[i - 2] * (i - 1)
// 2. Not to swap the first num with the ith num, dp[i] = dp[i - 1] * (i - 1)

class Solution {
    public int findDerangement(int n) {
        final long mod = (long)1e9 + 7;
        if (n == 1)    return 0;
        if (n == 2)    return 1;
        long[] dp = new long[n + 1];
        dp[1] = 0;    dp[2] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] = ((long)(i - 1) * (dp[i - 2] + dp[i - 1])) % mod;
        return (int)dp[n];
    }
}