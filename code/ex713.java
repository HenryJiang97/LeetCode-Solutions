// Sliding window

class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1)    return 0;
        int n = nums.length;
        
        int start = 0, end = 0, res = 0;
        int product = 1;
        while (end < n) {
            product *= nums[end];
            while (product >= k)    product /= nums[start++];
            res += end - start + 1;
            end++;
        }
        
        return res;
    }
}