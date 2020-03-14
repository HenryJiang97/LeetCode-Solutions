// O(n * k * k), O(n)

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();    if (n == 0)    return 0;
        int k = costs[0].size();    if (k == 0)    return 0;
        
        vector<int> dp(k);
        for (int j = 0; j < k; j++)    dp[j] = costs[0][j];
        for (int i = 1; i < n; i++) {
            vector<int> backup = dp;
            for (int j = 0; j < k; j++) {
                dp[j] = INT_MAX / 2;
                for (int z = 0; z < k; z++) {
                    if (j == z)    continue;
                    dp[j] = min(dp[j], backup[z] + costs[i][j]);
                }
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};