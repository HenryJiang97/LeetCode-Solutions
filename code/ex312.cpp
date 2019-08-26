class Solution {
    int n;
    
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        n = nums.size();    if (n == 2)    return 0;
        
        vector<vector<int>> memo(n, vector<int>(n));
        return recurrsion(nums, 1, n - 2, memo);
    }
    
private:
    int recurrsion(vector<int>& nums, int lo, int hi, vector<vector<int>>& memo) {
        if (lo > hi) {
            return 0;
        }
        
        if (memo[lo][hi] != 0)    return memo[lo][hi];
        int score = 0;
        for (int i = lo; i <= hi; i++) {
            score = max(score, recurrsion(nums, lo, i - 1, memo) + recurrsion(nums, i + 1, hi, memo) + nums[lo - 1] * nums[i] * nums[hi + 1]);
        }

        memo[lo][hi] = score;
        return score;
    }
};