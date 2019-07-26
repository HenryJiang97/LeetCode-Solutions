// Binary Search

class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 0)    return false;
        if (num == 1 || num == 4)    return true;
        
        int lo = 0, hi = num / 2;
        
        while (lo <= hi) {
            long mid = (long)((lo + hi) / 2);
            if (mid * mid == (long)num)    return true;
            else if (mid * mid < (long)num)    lo = (int)mid + 1;
            else if (mid * mid > (long)num)   hi = (int)mid - 1;
        }
        
        return false;
    }
}