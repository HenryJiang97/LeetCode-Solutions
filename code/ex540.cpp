class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            
            int left = mid - 1 >= 0 ? nums[mid - 1] : INT_MAX;
            int right = mid + 1 < n ? nums[mid + 1] : INT_MIN;
            if (left != nums[mid] && right != nums[mid])    return nums[mid];
            
            else if (mid % 2 == 0) {    // Currently at even index
                if (mid + 1 < n && nums[mid + 1] == nums[mid])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            
            else {    // Currently at odd index
                if (mid - 1 >= 0 && nums[mid - 1] == nums[mid])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        
        return 0;
    }
};