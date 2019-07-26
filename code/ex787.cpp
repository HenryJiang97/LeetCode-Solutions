class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Bellman-Ford
        vector<int> dp(n, INT_MAX);
        dp[dst] = 0;
        
        for (int k = 1; k < K + 2; k++) {
            auto backup = vector<int>();
            copy(dp.begin(), dp.end(), back_inserter(backup));
            for (auto& edge : flights) {
                if (backup[edge[1]] == INT_MAX)    continue;
                dp[edge[0]] = min(dp[edge[0]], backup[edge[1]] + edge[2]);
            }
        }

        return dp[src] == INT_MAX ? -1 : dp[src];
    }
};