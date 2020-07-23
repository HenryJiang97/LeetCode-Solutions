class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;    // XOR of every element
        for (int num : nums)    XOR ^= num;
        XOR &= -XOR;    // Get the first bit which is different
        
        // Group with that bit of 0
        int group1 = 0, group2 = 0;
        for (int num : nums) {
            if ((num & XOR) == 0)    group1 ^= num;
            else    group2 ^= num;
        }
        
        return {group1, group2};
    }
};