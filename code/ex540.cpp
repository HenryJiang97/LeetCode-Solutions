class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int left = mid > 0 ? nums[mid - 1] : INT_MIN;
            int right = mid < n - 1 ? nums[mid + 1] : INT_MAX;
            if (nums[mid] != left && nums[mid] != right)    return nums[mid];
            if (mid % 2 == 1) {    // Odd idx
                if (mid > 0 && nums[mid - 1] != nums[mid])    hi = mid - 1;
                else    lo = mid + 1;
            } else {    // Even idx
                if (mid < n - 1 && nums[mid + 1] != nums[mid])    hi = mid - 1;
                else    lo = mid + 1;
            }
        }
        return 0;
    }
};