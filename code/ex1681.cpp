class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        int len = n / k;
        
        // Get valid array for possible subsequences
        vector<int> dis(1 << n, -1);
        for (int i = 0; i < (1 << n); i++) {
            // Test if the combination is valid
            if (__builtin_popcount(i) != len)    continue;
            bool duplicate = 0;
            unordered_set<int> set;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 0)    continue;
                if (set.count(nums[j]) > 0) {
                    duplicate = 1;
                    break;
                }
                set.insert(nums[j]);
            }
            if (duplicate)    continue;
            
            // Get incompatibility 
            int MIN = INT_MAX, MAX = INT_MIN;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) == 0)    continue;
                MIN = min(MIN, nums[j]);
                MAX = max(MAX, nums[j]);
            }
            dis[i] = MAX - MIN;
        }
        
        // Bitmask dynamic programming
        vector<int> dp((1 << n), INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i < (1 << n); i++) {
            for (int cur = i; cur; cur = (cur - 1) & i) {
                if (dis[cur] == -1)    continue;
                dp[i] = min(dp[i], dp[i ^ cur] + dis[cur]);
            }
        }
        
        return dp[(1 << n) - 1] == INT_MAX / 2 ? -1 : dp[(1 << n) - 1];
    }
};