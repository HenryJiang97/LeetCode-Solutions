class Solution {
public:
    bool hasAlternatingBits(int n) {
        long XOR = n ^ (n >> 1);
        return !(XOR & (XOR + 1));
    }
};