class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int MAX = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * MAX + 1));
        dp[0][nums[0] + MAX] += 1;    dp[0][-nums[0] + MAX] += 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 2 * MAX; j++) {
                // +
                dp[i][j] += j - nums[i] >= 0 ? dp[i - 1][j - nums[i]] : 0;
                // -
                dp[i][j] += j + nums[i] <= 2 * MAX ? dp[i - 1][j + nums[i]] : 0;
            }
        }
        return S > MAX || S < -MAX ? 0 : dp[n - 1][S + MAX];
    }
};