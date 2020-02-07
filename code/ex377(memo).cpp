// dfs + memo

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, -1);
        return backtracking(nums, dp, target);
    }
    
private:
    int backtracking(vector<int>& nums, vector<unsigned long long>& dp, int target) {
        if (target == 0)    return 1;
        if (target < 0)    return 0;
        if (dp[target] != -1)    return dp[target];
        int cnt = 0;
        for (int n : nums)
            cnt += backtracking(nums, dp, target - n);
        dp[target] = cnt;
        return cnt;
    }
};