class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)    return 0;
        else if (n == 1)    return nums[0];
        else if (n == 2)    return max(nums[0], nums[1]);
        int dp11 = nums[0], dp1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int nxt = max(dp11 + nums[i], dp1);
            dp11 = dp1;
            dp1 = nxt;
        }
        return dp1;
    }
};