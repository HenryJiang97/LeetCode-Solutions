import java.util.Arrays;

class Solution {
    public void wiggleSort(int[] nums) {
        // Special situation
        if (nums.length == 0 || nums.length == 1)    return;
        
        // Duplicate the array and sort
        int[] backup = Arrays.copyOf(nums, nums.length);
        Arrays.sort(backup);
        
        
        // Divide the sorted array into two pieces from the middle
        int p1 = (nums.length - 1) / 2;
        int p2 = nums.length - 1;
        
        for (int i = 0; i < nums.length; i += 2) {
            nums[i] = backup[p1--];
            if (i + 1 < nums.length)    nums[i + 1] = backup[p2--];
        }
    }
}