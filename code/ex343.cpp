class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(59);
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int n1 = 1; n1 < i; n1++) {
                int n2 = i - n1;
                dp[i] = max(dp[i], dp[n1] * dp[n2]);
            }
            if (i == n)    return dp[i];
            dp[i] = max(dp[i], i);
        }
        
        return dp[n];
    }
};