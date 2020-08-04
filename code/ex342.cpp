class Solution {
public:
    bool isPowerOfFour(int num) {
        string bit = bitset<32>(num).to_string();
        return __builtin_popcount(num) == 1 && ((32 - bit.find('1') - 1) % 2 == 0);
    }
};