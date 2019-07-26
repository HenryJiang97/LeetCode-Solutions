import java.util.Arrays;

class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 1);

        int max = 0;


        for (int i = nums.length - 1; i >= 0; i--) {

            for (int j = nums.length - 1; j > i; j--) {
                if (nums[i] < nums[j])      dp[i] = Math.max(dp[i], dp[j] + 1);
            }

            max = Math.max(max, dp[i]);
        }


        return max;
    }
}