class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0, bit = 0;
        while (m > 0 && n > 0) {
            if (m == n && m % 2 == 1)    res = res | (1 << bit);
            bit++;
            m >>= 1;    n >>= 1;
        }
        return res;
    }
};