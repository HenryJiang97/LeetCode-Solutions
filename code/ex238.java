class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        
        result[0] = 1;
        
        // Get the product of elements to the left side of the target element
        for (int i = 1; i < nums.length; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        
        // Multiply the result with the product of elements to the right side of the target element
        int product = nums[nums.length - 1];
        
        for (int i = nums.length - 2; i >= 0; i--) {
            result[i] = result[i] * product;
            product *= nums[i];
        }
        
        
        return result;
    }
}