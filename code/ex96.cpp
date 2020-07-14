class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;    dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int l = 0; l <= i - 1; l++) {
                int r = i - 1 - l;
                dp[i] += dp[l] * dp[r];
            }
        }
        
        return dp[n];
    }
};