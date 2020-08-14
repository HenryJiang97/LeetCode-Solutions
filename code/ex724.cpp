class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();    if (n == 0)    return -1;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < n; i++) {
            if (left == sum - nums[i] - left)    return i;
            left += nums[i];
        }
        return -1;
    }
};