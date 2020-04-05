class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();    if (n == 0)    return {};
        sort(nums.begin(), nums.end());
        
        int MAX = 1, end_idx = 0;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], dp[j] + 1);
                if (dp[i] > MAX) {
                    MAX = dp[i];
                    end_idx = i;
                }
            }
        }
        
        // Get result
        vector<int> res;
        for (int i = end_idx, rest = MAX; i >= 0 && rest >= 0; i--) {
            if (dp[i] == rest && nums[end_idx] % nums[i] == 0) {
                res.push_back(nums[i]);
                rest--;
            }
        }
        
        return res;
    }
};