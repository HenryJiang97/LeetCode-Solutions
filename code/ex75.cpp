class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = n - 1, p = 0;
        while (p <= p2) {
            if (nums[p] == 0) {
                swap(nums[p++], nums[p1++]);
            } else if (nums[p] == 2) {
                swap(nums[p], nums[p2--]);
            } else {
                p++;
            }
        }
    }
};