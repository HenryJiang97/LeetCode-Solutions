class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int max = 0;
        int n = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1)    n++;
            else    {max = Math.max(n, max);    n = 0;}
        }
        max = Math.max(n, max);
        return max;
    }
}