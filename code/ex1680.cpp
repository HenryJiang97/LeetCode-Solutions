class Solution {
public:
    int concatenatedBinary(int n) {
        const int mod = 1e9 + 7;
        long res = 0;
        for (int i = 1; i <= n; i++) {
            int len = getBitLen(i);
            res = ((res << len) + i) % mod;
        }
        return (int)res;
    }
    
private:
    int nxt = 2;
    int len = 1;
    int getBitLen(int x) {
        if (x == nxt) {
            len++;
            nxt = nxt << 1;
        }
        return len;
    }
};