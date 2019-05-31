class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        while (x > 0 && y > 0) {
            if (x % 2 != y % 2)    cnt++;
            x = x >> 1;    y = y >> 1;
        }
        while (x > 0) {
            if (x % 2 != 0)    cnt++;
            x = x>>1;
        }
        while (y > 0) {
            if (y % 2 != 0)    cnt++;
            y = y>>1;
        }
        return cnt;
    }
};