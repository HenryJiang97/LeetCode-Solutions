class Solution {
    public void moveZeroes(int[] nums) {
        // Get numbers of zeros in the array
        int zeros = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0)   zeros++;
        }
        
        // Rearrange the array
        int counter = 0;
        int n = 0, i = 0;
        
        while (counter < nums.length - zeros) {
            if (nums[i] != 0) {
                nums[n] = nums[i];
                
                i++;    n++;    counter++;
            }
            else
                i++;
        }
        
        // Add zeros to the end
        for (int j = nums.length - zeros; j < nums.length; j++) nums[j] = 0;
        
    }
}