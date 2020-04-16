class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();    if (n == 1)    return 1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0 && !canOverpass(nums, i))
                return 0;
        }
        return 1;
    }
    
private:
    bool canOverpass(vector<int>& nums, int p) {
        for (int i = p - 1; i >= 0; i--) {
            if (i + nums[i] > p)    return 1;
        }
        return 0;
    }
};