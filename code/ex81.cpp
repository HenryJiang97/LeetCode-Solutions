class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Remove nums in the end of the array which is duplicate to the nums at the front
        while (nums.size() > 1 && nums.back() == nums[0])
            nums.pop_back();
        
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] == target)
                return 1;
            else if (nums[lo] > nums[mid]) {    // Pivot is in [lo : mid]
                if (target <= nums[hi] && target > nums[mid])    lo = mid + 1;
                else    hi = mid - 1;
            } else {    // Pivot is in [mid : hi]
                if (target >= nums[lo] && target < nums[mid])    hi = mid - 1;
                else    lo = mid + 1;
            }
        }
        
        return 0;
    }
};