class Solution {
    public int minPatches(int[] nums, int n) {
        int counter = 0;
        int i = 0;
        
        long missing = 1;
        while (missing <= n) {
            if (i < nums.length && nums[i] <= missing) 
                missing += nums[i++];
            else {
                counter++;
                missing += missing;
            }
        }
        
        return counter;
    }
}