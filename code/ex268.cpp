class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            while (nums[i] < n && nums[nums[i]] != nums[i]) {
                swap(nums[nums[i]], nums[i]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i)    return i;
        }
        
        return n;
    }
};