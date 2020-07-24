class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        vector<long> prefix{0};
        for (int num : nums)    prefix.push_back(num + prefix.back());
        
        vector<long> dp(n);
        for (int i = 0; i < n; i++)    dp[i] = prefix[i + 1];
        
        for (int l = 2; l <= m; l++) {
            for (int i = n - 1; i >= 0; i--) {
                for (int j = i - 1; j >= 0; j--) {
                    dp[i] = min(dp[i], max(dp[j], prefix[i + 1] - prefix[j + 1]));
                }
            }
        }
        
        return dp[n - 1];
    }
};