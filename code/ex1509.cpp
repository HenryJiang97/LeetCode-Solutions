class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();    if (n <= 4)    return 0;
        sort(nums.begin(), nums.end());
        int MIN = INT_MAX;
        for (int lo = 0; lo <= 3; lo++) {
            int hi = 3 - lo;
            MIN = min(MIN, nums[n - 1 - hi] - nums[lo]);
        }
        return MIN;
    }
};