class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int n : nums)
            x ^= n;
        if (x == 0)    return 1;
        return nums.size() % 2 == 0;
    }
};