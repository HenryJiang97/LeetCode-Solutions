class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) {
            addRange(res, lower, upper);
            return res;
        }
        if (nums[0] > lower)    addRange(res, lower, nums[0] - 1);
        int prev = max(nums[0], lower);
        for (int i = 1; i < n; i++) {
            addRange(res, prev + 1, nums[i] - 1);
            prev = nums[i];
        }
        if (nums.back() < upper)    addRange(res, nums.back() + 1, upper);
        return res;
    }
    
private:
    void addRange(vector<string>& res, int lo, int hi) {
        if (lo > hi)    return;
        res.push_back(lo == hi ? to_string(lo) : to_string(lo) + "->" + to_string(hi));
    }
};