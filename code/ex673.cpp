class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int MAX = 1;
        vector<vector<int>> dp(n, vector<int>(2, 1));    // {Max_len, cnt}
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    if (dp[j][0] + 1 == dp[i][0]) {
                        dp[i][1] += dp[j][1];
                    } else if (dp[j][0] + 1 > dp[i][0]) {
                        dp[i][0] = dp[j][0] + 1;
                        dp[i][1] = dp[j][1];
                    }
                }
            }
            MAX = max(MAX, dp[i][0]);
        }

        // Get the count of max LIS
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i][0] == MAX) {
                cnt += dp[i][1];
            }
        }
        return cnt;
    }
};