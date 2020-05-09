class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0)    return 0;
        int lo = 0, hi = 46340;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid * mid == num)    return 1;
            else if (mid * mid < num)    lo = mid + 1;
            else    hi = mid - 1;
        }
        return 0;
    }
};