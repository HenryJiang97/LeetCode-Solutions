class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        
        // Get prefix sum array
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        
        // DFS + memo
        vector<vector<unordered_map<int, bool>>> memo(n, vector<unordered_map<int, bool>>(4, unordered_map<int, bool>()));
        bool res = 0;
        for (int i = 0; i < n; i++) {
            int sum = prefix[i + 1];
            res |= backtracking(nums, prefix, memo, i + 2, 1, sum);
            if (res)    return 1;
        }
        
        return res;
    }
    
private:
    bool backtracking(vector<int>& nums, vector<int>& prefix, vector<vector<unordered_map<int, bool>>>& memo, int s, int t, int sum) {
        int n = nums.size();
        if (s >= nums.size())    return 0;
        if (t == 3) {
            return prefix[n] - prefix[s] == sum;
        }
        
        if (memo[s][t].find(sum) != memo[s][t].end()) {
            return memo[s][t][sum];
        }
        
        bool res = 0;
        for (int i = s; i < n; ++i) {
            if (prefix[i + 1] - prefix[s] != sum)    continue;
            res |= backtracking(nums, prefix, memo, i + 2, t + 1, sum);
            if (res)    return 1;
        }
        
        memo[s][t][sum] = res;
        return res;
    }
};