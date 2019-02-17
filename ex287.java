class Solution {
    public int findDuplicate(int[] nums) {
        int[] record = new int[nums.length];

        for (int i = 0; i < nums.length; i++) {
            if (record[nums[i] - 1] == 1)   return nums[i];
            record[nums[i] - 1]++;
        }

        return 0;
    }
}