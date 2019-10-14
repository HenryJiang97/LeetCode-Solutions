class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
    
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else if (nums[mid] < nums[hi])
                hi = mid;
            else    // nums[mid] == nums[hi]
                hi--;    // Remove the num at the end, no impact to result since nums[mid] == nums[hi], still at least one left
        }
        
        return nums[lo];
    }
};