class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)    return 0;
        int up = 1, down = 1, MAX = 1;
        for (int i = 1; i < n; i++) {
            int bkpUp = up, bkpDown = down;
            if (nums[i] > nums[i - 1])
                up = max(up, bkpDown + 1);
            if (nums[i] < nums[i - 1])
                down = max(down, bkpUp + 1);
            MAX = max(MAX, max(up, down));
        }
        return MAX;
    }
};