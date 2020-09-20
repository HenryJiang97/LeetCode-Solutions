class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        int lo = 0, hi = 0, pro = 1, res = 0;
        while (hi < n) {
            pro *= nums[hi];
            while (lo <= hi && pro >= k) {
                pro /= nums[lo++];
            }
            res += hi - lo + 1;
            hi++;
        }
        
        return res;
    }
};