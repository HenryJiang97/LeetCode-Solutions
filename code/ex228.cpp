class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();    if (n == 0)    return {};
        vector<string> res;
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0)    prev = nums[i];
            else {
                if ((long)nums[i] - nums[i - 1] > 1l) {
                    res.push_back(nums[i - 1] - prev == 0 ? to_string(nums[i - 1]) : to_string(prev) + "->" + to_string(nums[i - 1]));
                    prev = nums[i];
                }
            }
        }
        res.push_back(nums[n - 1] - prev == 0 ? to_string(nums[n - 1]) : to_string(prev) + "->" + to_string(nums[n - 1]));
        return res;
    }
};