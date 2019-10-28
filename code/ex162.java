class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        if (n <= 1)    return 0;
        
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (mid == 0 && nums[mid + 1] < nums[mid])
                return mid;
            else if (mid == n - 1 && nums[mid - 1] < nums[mid])
                return mid;
            else if (mid - 1 >= 0 && mid + 1 < n && nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid + 1] > nums[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return 0;
    }
}