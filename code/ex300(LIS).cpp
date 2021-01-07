class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            if (arr.empty() || arr.back() < nums[i]) {
                arr.push_back(nums[i]);
            } else {
                auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return arr.size();
    }
};