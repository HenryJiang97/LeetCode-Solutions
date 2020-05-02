class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int nr = ring.length(), nk = key.length();
        
        unordered_map<char, vector<int>> m;
        for (int i = 0; i < nr; i++)
            m[ring[i]].push_back(i);
        
        // DP
        vector<vector<int>> dp(nk + 1, vector<int>(nr, INT_MAX / 2));
        dp[0][0] = 0;
        char prev = ring[0];
        for (int i = 1; i <= nk; i++) {
            char cur = key[i - 1];
            for (int curj : m[cur]) {
                for (int prevj : m[prev]) {
                    dp[i][curj] = min(dp[i][curj], dp[i - 1][prevj] + min(abs(curj - prevj), nr - abs(curj - prevj)) + 1);
                }
            }
            prev = cur;
        }
        
        // Get result
        int res = INT_MAX;
        for (int j = 0; j < nr; j++)
            res = min(res, dp[nk][j]);
        
        return res;
    }
};