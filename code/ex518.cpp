class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[j] += j - coins[i] >= 0 ? dp[j - coins[i]] : 0;
            }
        }
        return dp[amount];
    }
};