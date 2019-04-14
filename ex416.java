// Knapsack

class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 != 0)    return false;
        sum /= 2;
        
        boolean[][] dp = new boolean[nums.length + 1][sum + 1];
        dp[0][0] = true;
        
        for (int i = 1; i < nums.length + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] |= dp[i - 1][j - nums[i - 1]];
            }
            if (dp[i][sum])    return true;
        }
        
        return false;
    }
}