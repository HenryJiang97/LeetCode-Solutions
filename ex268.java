import java.util.Arrays;

class Solution {
    public int missingNumber(int[] nums) {
        // Sort the array
        Arrays.sort(nums);

        // Check
        int pointer = 0;

        while (pointer < nums.length) {
            if (nums[pointer] != pointer)
                return pointer;

            pointer++;
        }

        return pointer;
    }
}