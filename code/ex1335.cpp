class Solution {
public:
    int minDifficulty(vector<int>& jd, int D) {
        int n = jd.size();
        if (D > n)    return -1;
        
        vector<int> dp(n, INT_MAX / 2);
        int max_diff = 0;
        for (int i = 0; i < n; i++) {
            max_diff = max(max_diff, jd[i]);
            dp[i] = max_diff;
        }
        
        for (int d = 2; d <= D; d++) {
            for (int i = n - 1; i >= 0; i--) {
                dp[i] = INT_MAX / 2;
                max_diff = jd[i];
                for (int j = i - 1; j >= 0; j--) {
                    max_diff = max(max_diff, jd[j + 1]);
                    dp[i] = min(dp[i], dp[j] + max_diff);
                }
            }
        }
        
        return dp[n - 1];
    }
};