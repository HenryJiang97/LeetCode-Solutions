// 2D-DP

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        // Get the target sum of each subset
        int sum = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)    return 0;
        sum /= 2;
        
        // Dynamic programming through the nums array to find out if an subset with sum of target exists
        bool dp[n + 1][sum + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
                if (j - nums[i - 1] >= 0)
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        
        return dp[n][sum];
    } 
};