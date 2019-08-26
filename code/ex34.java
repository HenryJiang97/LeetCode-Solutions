// Binary Search (O(logn))

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;
        
        int[] res = new int[]{-1, -1};
        if (n == 0)    return res;
        if (n == 1) {
            if (nums[0] == target)    return new int[]{0, 0};
            else    return res;
        }
        
        // Find the first position of target
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if (nums[mid] >= target) {
                if (nums[mid] == target)    res[0] = mid;
                hi = mid - 1;
            } else {
                if (mid + 1 < n && nums[mid + 1] == target) {
                    res[0] = mid + 1;
                    break;
                } else {
                    lo = mid + 1;
                }
            }
        }
        
        // Find the second position of target
        lo = 0;    hi = n - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            if (nums[mid] <= target) {
                if (nums[mid] == target)    res[1] = mid;
                lo = mid + 1;
            } else {
                if (mid - 1 >= 0 && nums[mid - 1] == target) {
                    res[1] = mid - 1;
                    break;
                } else {
                    hi = mid - 1;
                }
            }
        }
        
        return res;
    }
}