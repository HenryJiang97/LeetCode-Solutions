class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        long lo = INT_MIN, hi = INT_MAX;
        while (lo < hi) {
            long mid = lo + (hi - lo + 1) / 2;
            if (getCnt(nums, mid) >= k)    lo = mid;
            else    hi = mid - 1;
        }
        return (int)hi;
    }
    
private:
    // Get the number of nums in the array which are >= val
    int getCnt(vector<int>& nums, long val) {
        int cnt = 0;
        for (int num : nums)
            if (num >= val)    cnt++;
        return cnt;
    }
};