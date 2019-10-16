class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[lo] > nums[mid]) {    // Pivot is in [lo : mid]
                if (target <= nums[hi] && target > nums[mid])    lo = mid + 1;
                else    hi = mid - 1;
            } else {    // Pivot is in [mid : hi]
                if (target >= nums[lo] && target < nums[mid])    hi = mid - 1;
                else    lo = mid + 1;
            }
        }
        
        return -1;
    }
};