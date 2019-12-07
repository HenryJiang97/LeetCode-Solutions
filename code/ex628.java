class Solution {
    public int maximumProduct(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        return Math.max(Math.max(nums[0] * nums[1] * nums[2], nums[0] * nums[1] * nums[n - 1]), Math.max(nums[n - 1] * nums[n - 2] * nums[0], nums[n - 1] * nums[n - 2] * nums[n - 3]));
    }
}