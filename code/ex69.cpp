// Binary search

typedef long long ll;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)    return x;
        
        // Run binary search for an n^2 == x or just smaller than x
        ll lo = 1, hi = x / 2;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
            
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid > x) {
                hi = mid - 1;
            } else {
                if ((mid + 1) * (mid + 1) > x)
                    return mid;
                else
                    lo = mid + 1;
            }
        }
        
        return -1;
    }
};