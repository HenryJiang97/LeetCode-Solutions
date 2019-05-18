// 2D - DP
// dp[i][j - nums[i]] += dp[i - 1][j];
// dp[i][j + nums[i]] += dp[i - 1][j];

class Solution {
    public int findTargetSumWays(int[] nums, int S) {
        // Max possible sum for nums
        int max = 0;
        for (int num : nums)    max += num;
        
        // Build dp array
        int[][] dp = new int[nums.length][max * 2 + 1];
        dp[0][nums[0] + max]++;
        dp[0][-nums[0] + max]++;
        
        for (int i = 1; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                if (dp[i - 1][j] != 0) {
                    dp[i][j - nums[i]] += dp[i - 1][j];
                    dp[i][j + nums[i]] += dp[i - 1][j];
                }
            }
        }
        
        // Test
        // for (int i = 0; i < dp.length; i++) {
        //     for (int j = 0; j < dp[0].length; j++) {
        //         System.out.print(dp[i][j]);
        //         System.out.print(" ");
        //     }
        //     System.out.println();
        // }
        
        return (S <= max && S >= -max) ? dp[nums.length - 1][S + max] : 0;
    }
}