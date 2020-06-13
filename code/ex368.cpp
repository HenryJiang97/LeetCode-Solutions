class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();    if (n == 0)    return {};
        sort(nums.begin(), nums.end());
        
        int MAX = 1, end = 0;
        vector<int> dp(n, 1), prev(n);
        for (int i = 0; i < n; i++) {
            prev[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > MAX) {
                MAX = dp[i];
                end = i;
            }
        }
        
        // Get subset
        vector<int> res;
        while (1) {
            res.push_back(nums[end]);
            if (prev[end] == end)    break;
            end = prev[end];
        }
        
        return res;
    }
};