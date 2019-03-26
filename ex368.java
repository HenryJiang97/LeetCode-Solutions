import java.util.*;

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        if (nums.length == 0)    return new ArrayList<Integer>();
        
        Arrays.sort(nums);
        
        // Use dp to find the max length of the subset and the index of max number in the subset
        int max = 0, maxIndex = 0;
        int[] dp = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i - 1; j >= 0; j--)
                if (nums[i] % nums[j] == 0)
                    dp[i] = Math.max(dp[i], dp[j] + 1);

            if (dp[i] == 0)    dp[i] = 1;
            
            if (dp[i] > max) {
                max = dp[i];
                maxIndex = i;
            }
        }
        
        List<Integer> res = new ArrayList<>();
        // Find all the numbers in the array which can be divisible by nums[maxIndex] and add them to the list
        int dividend = nums[maxIndex], restLen = max;
        for (int i = maxIndex; i >= 0 && restLen >= 0; i--)
            if (dp[i] == restLen && dividend % nums[i] == 0) {
                res.add(nums[i]);
                dividend = nums[i];
                restLen--;
            }
                
        
        return res;
    }
}