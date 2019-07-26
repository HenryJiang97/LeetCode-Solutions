// 2D-DP knapsack, dp[i][j] => use up to i coins which makes up to j amount

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount < 1)    return 1;
        
        int n = coins.size();
        auto dp = vector<vector<int>>(n + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i <= n; i++)    dp[i][0] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // If current coin is larger than amound, skip this coin
                if (j < coins[i - 1])    dp[i][j] = dp[i - 1][j];
                else    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
        }
        
        return dp[n][amount];
    }
};