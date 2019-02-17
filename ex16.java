import java.util.Arrays;

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int lo, hi;
        int sum;
        // Min: record the closest result to the target
        int min = nums[0] + nums[1] + nums[2];
        
        // Sort the array first
        Arrays.sort(nums);
        
        for (int i = 0; i < nums.length - 2; i++) {
            lo = i + 1;
            hi = nums.length - 1;
            
            while (lo < hi) {
                sum = nums[i] + nums[lo] + nums[hi];
                
                if (sum > target) {
                    hi--;
                    min = (sum - target < Math.abs(min - target)) ? sum : min;
                } else if (sum < target) {
                    lo++;
                    min = (target - sum < Math.abs(min - target)) ? sum : min;
                } else 
                    return target;
            }
        }
        
        return min;
    }
}