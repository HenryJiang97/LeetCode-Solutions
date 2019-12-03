class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        int n = nums.length;
        int min = Integer.MAX_VALUE;
        
        int lo = 0, hi = 0, sum = 0;
        for (hi = 0; hi < n; hi++) {
            sum += nums[hi];
            while (sum >= s) {
                min = Math.min(min, hi - lo + 1);
                sum -= nums[lo++];
            }
        }
        
        return min == Integer.MAX_VALUE ? 0 : min;
    }
}