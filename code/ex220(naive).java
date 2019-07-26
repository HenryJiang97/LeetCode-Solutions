// O(n * k)

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        long lt = t;
        
        for (int i = 0; i < nums.length; i++) {
            int j = i + 1;
            while (j < nums.length && j <= i + k) {
                if (Math.abs((long)nums[i] - (long)nums[j]) <= lt)    return true;
                j++;
            }
        }
        
        return false;
    }
}