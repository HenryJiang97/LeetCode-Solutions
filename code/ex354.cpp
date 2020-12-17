class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();    if (n == 0)    return 0;
        sort(env.begin(), env.end());
        reverse(env.begin(), env.end());
        int MAX = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (env[j][0] > env[i][0] && env[j][1] > env[i][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            MAX = max(MAX, dp[i]);
        }
        return MAX;
    }
};