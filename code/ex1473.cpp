class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[i][j][k] => ending at idx i, with ending color of j, has k neighbourhood before
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, INT_MAX / 2)));
        
        // Initialize
        for (int j = 1; j <= n; j++) {
            if (houses[0] == j)    dp[0][j][1] = 0;
            else if (houses[0] == 0)    dp[0][j][1] = cost[0][j - 1];
        }

        // Build dp array
        for (int i = 1; i < m; i++) {
            if (houses[i] != 0) {    // Has color, do not change any more
                int co = houses[i];
                for (int pco = 1; pco <= n; pco++) {
                    for (int k = 1; k <= target; k++) {
                        if (pco == co)    // Previous house color is the same as current house
                            dp[i][co][k] = min(dp[i][co][k], dp[i - 1][co][k]);
                        else    // Previous house color is different from current house
                            dp[i][co][k] = min(dp[i][co][k], dp[i - 1][pco][k - 1]);
                    }
                }
            }
            else {    // Do not have color, paint it
                for (int co = 1; co <= n; co++) {
                    for (int pco = 1; pco <= n; pco++) {
                        for (int k = 1; k <= target; k++) {
                            if (pco == co)    // Previous house color is the same as current house
                                dp[i][co][k] = min(dp[i][co][k], dp[i - 1][pco][k] + cost[i][co - 1]);
                            else    // Previous house color is different from current house
                                dp[i][co][k] = min(dp[i][co][k], min(dp[i - 1][pco][k - 1], dp[i - 1][co][k]) + cost[i][co - 1]);
                        }
                    }
                }
            }
        }
        
        // Get result
        int MIN = INT_MAX / 2;
        for (int co = 1; co <= n; co++) {
            MIN = min(MIN, dp[m - 1][co][target]);
        }
        
        return MIN == INT_MAX / 2 ? -1 : MIN;
    }
};