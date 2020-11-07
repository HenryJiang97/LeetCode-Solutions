class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int left = 0; left <= i - 1; left++) {
                int right = i - 1 - left;
                dp[i] += dp[left] * dp[right];
            }
        }
        return dp.back();
    }
};