// DP
// dp1[i] => The subarray with maximum positive product ended at i
// dp2[i] => The subarray with maximum negative product ended at i, max of abs(subarray product)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();    if (n == 0)    return 0;
        
        auto dp1 = vector<int>(n, 0);
        auto dp2 = vector<int>(n, 0);
        dp1[0] = nums[0] > 0 ? nums[0] : 0;
        dp2[0] = nums[0] < 0 ? nums[0] : 0;
        
        int MAX = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                dp1[i] = max(nums[i], dp1[i - 1] * nums[i]);
                dp2[i] = dp2[i - 1] * nums[i];
            } else if (nums[i] < 0) {
                dp1[i] = dp2[i - 1] * nums[i];
                dp2[i] = min(nums[i], dp1[i - 1] * nums[i]);
            }
            
            MAX = max(MAX, dp1[i]);
        }
        
        return MAX;
    }
};