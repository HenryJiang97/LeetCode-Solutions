class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (int num : nums)
            XOR ^= num;
        return XOR;
    }
};