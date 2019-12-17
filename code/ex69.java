class Solution {
    public int mySqrt(int x) {
        if (x == 0)    return 0;
        
        long lo = 1, hi = 100000;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2 + 1;
            if (mid * mid > x)
                hi = mid - 1;
            else
                lo = mid;
        }
        
        return (int)lo;
    }
}