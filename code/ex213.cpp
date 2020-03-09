class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)    return 0;
        else if (n < 2)    return nums[0];
        
        // If robbing the first house
        int dp11 = nums[0], dp1 = dp11;
        for (int i = 2; i < n - 1; i++) {
            int newDp = max(dp11 + nums[i], dp1);
            dp11 = dp1;
            dp1 = newDp;
        }
        int first = dp1;
        
        // If not robbing the first house
        dp11 = 0;    dp1 = nums[1];
        for (int i = 2; i < n; i++) {
            int newDp = max(dp11 + nums[i], dp1);
            dp11 = dp1;
            dp1 = newDp;
        }
        int second = dp1;
        
        return max(first, second);
    }
};