class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)    return 0;
        
        int pos = max(nums[0], 0);
        int neg = min(nums[0], 0);
        int MAX = nums[0];
        
        for (int i = 1; i < n; i++) {
            int ppos = pos, pneg = neg;
            if (nums[i] >= 0) {
                pos = ppos * nums[i] < nums[i] ? nums[i] : ppos * nums[i];
                neg = pneg * nums[i];
            } else {
                pos = pneg * nums[i];
                neg = ppos * nums[i] > nums[i] ? nums[i] : ppos * nums[i];
            }
            MAX = max(MAX, pos);
        }
        
        return MAX;
    }
};