class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();    if (n <= 1)    return 0;
        int jumps = 0, i = 0;
        while (1) {
            int nxtJump = nums[i];
            int nxt = -1, MAX = INT_MIN;
            for (int j = i + 1; j <= min(i + nxtJump, n - 1); j++) {
                if (j == n - 1)    return jumps + 1;
                if (j + nums[j] > MAX) {
                    MAX = j + nums[j];
                    nxt = j;
                }
            }
            i = nxt;
            jumps++;
        }
        return -1;
    }
};