// Seperate the nums array into several section with each section length of k
class Solution {  
    public int[] maxSlidingWindow(int[] nums, int k) {     
        if (nums.length == 0) {
            return new int[0];
        }
        
        // Define two max array to record the max integer to the left and right of each element within each section
        int[] max_left = new int[nums.length];
        int[] max_right = new int[nums.length];
        
        // Initialize the first element of the two max arrays
        max_left[0] = nums[0];
        max_right[nums.length - 1] = nums[nums.length - 1];

        // Loop through nums to get the rest elements for two max arrays
        for (int i = 1; i < nums.length; i++) {
            // Deal with max_left
            if (i % k != 0) {
                if (max_left[i - 1] > nums[i])
                    max_left[i] = max_left[i - 1];
                else
                    max_left[i] = nums[i];
            } else  max_left[i] = nums[i];

            // Deal with max_right
            int j = nums.length - i - 1;

            if ((j + 1) % k != 0) {
                if (max_right[j + 1] > nums[j])
                    max_right[j] = max_right[j + 1];
                else
                    max_right[j] = nums[j];
            } else  max_right[j] = nums[j];
        }
        

        // Get the result array by "result[i] = Max(max_right[i], max_left[i + k - 1])"
        int[] result = new int[nums.length - k + 1];
        
        for (int i = 0; i < nums.length - k + 1; i++) {
            result[i] = Math.max(max_right[i], max_left[i + k - 1]);
        }
        

        return result;
    }
}