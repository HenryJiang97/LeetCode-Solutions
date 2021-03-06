class Solution {
public:
    int findComplement(int num) {
        int res = 0, i = 0;
        while (num > 0) {
            int d = (num & 1 == 1) ? 0 : 1;
            res |= (d << (i++));
            num >>= 1;
        }
        return res;
    }
};