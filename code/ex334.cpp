class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();    if (n < 3)    return 0;
        vector<int> premin;
        for (int i = 0; i < n; i++) {
            premin.push_back(i == 0 ? nums[0] : min(premin.back(), nums[i]));
        }
        
        int postmax = nums.back();
        for (int i = n - 2; i >= 1; i--) {
            if (nums[i] > premin[i - 1] && nums[i] < postmax)    return 1;
            postmax = max(postmax, nums[i]);
        }
        return 0;
    }
};