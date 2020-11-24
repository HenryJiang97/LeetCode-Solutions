class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3, INT_MIN / 2);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            vector<int> prev = dp;
            for (int m = 0; m < 3; m++) {    // Mod
                dp[m] = max(dp[m], prev[m]);
                dp[(m + nums[i]) % 3] = max(dp[(m + nums[i]) % 3], prev[m] + nums[i]);
            }
        }
        return dp[0];
    }
};