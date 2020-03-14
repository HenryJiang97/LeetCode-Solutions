class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int notFlip = 0, flip = 0, MAX = 0;
        for (int i = 1; i <= n; i++) {
            if (nums[i - 1] == 0) {
                flip = notFlip + 1;
                notFlip = 0;
            } else {
                notFlip++;
                flip++;
            }
            MAX = max(MAX, max(flip, notFlip));
        }
        return MAX;
    }
};