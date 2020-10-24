class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<int> prefix{0};
        for (int i = 0; i < n; i++)    prefix.push_back(prefix.back() + nums[i]);
        
        int MAX = 0;
        vector<int> dp(n + 1);
        unordered_map<int, int> map{{0, 0}};
        for (int i = 0; i < n; i++) {
            if (map.count(prefix[i + 1] - target) > 0) {
                dp[i + 1] = max(dp[i + 1], dp[map[prefix[i + 1] - target]] + 1);
            }
            dp[i + 1] = max(dp[i + 1], dp[i]);
            map[prefix[i + 1]] = i + 1;
        }
        
        return dp.back();
    }
};