// Maintain[i][j], i, j => number of exisiting subarray ahead of position j

class Solution {
    public int splitArray(int[] nums, int m) {
        // Init dp array
        int[][] dp = new int[m][nums.length];
        
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            dp[0][i] = sum;
        }
        
        // Build dp array
        for (int i = 1; i < m; i++) {
            for (int j = i; j < nums.length; j++) {
                int min = Integer.MAX_VALUE;
                for (int k = 0; k < j; k++) {
                    min = Math.min(min, Math.max(dp[i - 1][k], dp[0][j] - dp[0][k]));
                }
                dp[i][j] = min;
            }
        }
        
        // // Print dp array
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < nums.length; j++) {
        //         System.out.print(dp[i][j]);
        //         System.out.print(" ");
        //     }
        //     System.out.println();
        // }
        
        return dp[m - 1][nums.length - 1];
    }
}