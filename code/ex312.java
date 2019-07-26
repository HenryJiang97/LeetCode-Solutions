import java.util.*;

class Solution {
    public int dp[][];

    // Method to get value for nums[i], considering boundaries
    private int get(int[] nums, int i) {
        if (i < 0 || i >= nums.length)    return 1;
        return nums[i];
    }

    public int DAC(int[] nums, int lo, int hi) {
        if (lo > hi)    return 0;

        // Get result if already exists in dp array
        if (dp[lo][hi] != -1)    return dp[lo][hi];

        int maximum = 0;

        for (int i = lo; i <= hi; i++) {
            // Divide the array into five parts,
            // start - 1, maxCoin(start, i - 1), i, maxCoins(i + 1, end), end + 1,
            // Treat maxCoin(start, i - 1) and maxCoins(i + 1, end) recursion case as two bursted balloons
            int coin =  DAC(nums, lo, i - 1) + DAC(nums, i + 1, hi) + nums[i] * get(nums, lo - 1) * get(nums, hi + 1);

            maximum = Math.max(maximum, coin);
        }

        // Save the maximum result to dp array for later use
        dp[lo][hi] = maximum;

        return maximum;
    }
    
    public int maxCoins(int[] nums) {
        dp = new int[nums.length][nums.length];
        for (int i = 0; i < dp.length; i++)    Arrays.fill(dp[i], -1);

        return DAC(nums, 0, nums.length - 1);
    }
}