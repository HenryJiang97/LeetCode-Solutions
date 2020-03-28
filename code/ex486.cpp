class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MIN));
        return backtracking(nums, 0, n - 1, memo) >= 0;
    }
    
private:
    int backtracking(vector<int>& nums, int lo, int hi, vector<vector<int>>& memo) {
        if (lo == hi)    return nums[lo];
        if (memo[lo][hi] != INT_MIN)    return memo[lo][hi];
        int MAX = max(nums[lo] - backtracking(nums, lo + 1, hi, memo), nums[hi] - backtracking(nums, lo, hi - 1, memo));
        memo[lo][hi] = MAX;
        return MAX;
    }
};