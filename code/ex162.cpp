class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long left = mid - 1 >= 0 ? nums[mid - 1] : LONG_MIN;
            long right = mid + 1 < n ? nums[mid + 1] : LONG_MIN;
            if ((long)nums[mid] > left && (long)nums[mid] > right)    return mid;
            if (left <= (long)nums[mid])    lo = mid + 1;
            else    hi = mid - 1;
        }
        return lo;
    }
};