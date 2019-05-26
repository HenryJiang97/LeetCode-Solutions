// Math, treat each move as minus 1 to the max num in the array, move = sum{nums[i] - min}

class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() <= 1)    return 0;
        int _min = nums[0];
        for (auto num : nums)    _min = min(_min, num);
        int move = 0;
        for (auto num : nums)    move += (num - _min);
        return move;
    }
};