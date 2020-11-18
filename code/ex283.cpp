class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = 0;
        while (hi < n) {
            while (hi < n && nums[hi] == 0)    hi++;
            if (hi < n) {
                swap(nums[lo++], nums[hi++]);
            }
        }
    }
};