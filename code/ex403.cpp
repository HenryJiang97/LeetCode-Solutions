class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        // Get {val, idx} map
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++)
            map[stones[i]] = i;
        
        vector<unordered_set<int>> dp(n, unordered_set<int>());
        // First jump
        if (stones[1] > stones[0] + 1)    return 0;
        dp[0].insert(1);
        
        for (int i = 0; i < n; i++) {
            for (int k : dp[i]) {
                int nxt = map[stones[i] + k];
                if (nxt == n - 1)    return 1;
                for (int d = -1; d <= 1; d++) {
                    int nxtK = k + d;
                    if (nxtK <= 0 || map.count(stones[nxt] + nxtK) == 0)    continue;
                    dp[nxt].insert(nxtK);
                }
            }
        }
        
        return 0;
    }
};