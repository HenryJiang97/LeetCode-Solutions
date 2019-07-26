// Binary search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();    if (n == 1)    return nums[0];
        int lo = 0, hi = n - 1;
        
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            
            // Judge if nums[mid] is the target
            if (mid == 0) {
                if (nums[mid] != nums[mid + 1])    return nums[mid];
            } else if (mid == n - 1) {
                if (nums[mid] != nums[mid - 1])    return nums[mid];
            } else {
                if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                    return nums[mid];
            }
            
            // Binary search left or right
            if (mid % 2 == 0) {    // Even index
                if (mid + 1 < n && nums[mid] == nums[mid + 1])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            } else {    // Odd index
                if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        
        return 0;
    }
};