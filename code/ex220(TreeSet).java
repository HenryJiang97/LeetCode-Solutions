import java.util.*;

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        TreeSet<Integer> treeset = new TreeSet<>();
        
        for (int i = 0; i < nums.length; ++i) {
            // Find the smallest num in the set larger than nums[i]
            Integer hi = treeset.ceiling(nums[i]);
            // Find the largest num in the set smaller than nums[i]
            Integer lo = treeset.floor(nums[i]);

            // Check if two boundaries meets the requirement
            if (hi != null && (long)hi - (long)nums[i] <= (long)t)    return true;
            if (lo != null && (long)nums[i] - (long)lo <= (long)t)    return true;
            
            treeset.add(nums[i]);

            if (treeset.size() > k)    treeset.remove(nums[i - k]);
        }

        return false;
    }
}