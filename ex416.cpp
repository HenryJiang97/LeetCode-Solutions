// 2D-DP

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        // Get the target sum of each subset
        int sum = 0;
        for (auto num : nums)    sum += num;
        if (sum % 2 != 0)    return false;
        int target = sum / 2;
        
        // Dynamic programming through the nums array to find out if an subset with sum of target exists
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];    // Not pick certain element, leave it for the second subset
                
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
            if (dp[i][target])    return true;
        }
        
        return dp[n][target];
    } 
};