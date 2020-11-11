class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int nr = ring.length(), nk = key.length();
        
        vector<vector<int>> dict(26);
        for (int i = 0; i < nr; i++) {
            dict[ring[i] - 'a'].push_back(i);
        }
        
        // DP
        vector<vector<int>> dp(nk, vector<int>(nr, INT_MAX / 2));
        for (int i = 0; i < nk; i++) {
            for (int cur : dict[key[i] - 'a']) {
                if (i == 0)    dp[i][cur] = min(dp[i][cur], min(cur, nr - cur) + 1);
                else {
                    for (int prev : dict[key[i - 1] - 'a']) {
                        dp[i][cur] = min(dp[i][cur], dp[i - 1][prev] + min(abs(cur - prev), nr - abs(cur - prev)) + 1);
                    }
                }
            }
        }
        
        // Get result
        int res = INT_MAX / 2;
        for (int j = 0; j < nr; j++) {
            res = min(res, dp[nk - 1][j]);
        }
        return res;
    }
};