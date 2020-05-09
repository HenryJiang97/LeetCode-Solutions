class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)    return 0;
        int lo = 1, hi = min(x / 2, 46340);
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (mid * mid <= x)    lo = mid;
            else    hi = mid - 1;
        }
        return lo;
    }
};