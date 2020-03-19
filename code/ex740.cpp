class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int points[10001] = {0};
        for (auto num : nums)    points[num] += num;
        
        vector<int> dp(10001);
        for (int i = 1; i <= 10000; i++) {
            dp[i] = max(dp[i - 1], points[i]);
            if (i - 2 >= 0)
                dp[i] = max(dp[i], dp[i - 2] + points[i]);
        }
        
        return dp[10000];
    }
};