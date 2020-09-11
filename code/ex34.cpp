class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size(), start = -1, end = -1;
        if (n == 0)    return {-1, -1};
        
        // Find the starting index of target
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target)    hi = mid;
            else    lo = mid + 1;
        }
        if (nums[hi] != target)    return {-1, -1};
        start = hi;
        
        // Find the ending index of target
        lo = 0;    hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (nums[mid] <= target)    lo = mid;
            else    hi = mid - 1;
        }
        if (nums[lo] != target)    return {-1, -1};
        end = lo;
        
        return {start, end};
    }
};