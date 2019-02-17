class Solution {
    public boolean isPowerOfTwo(int n) {
        double p = 2.0;
        double q = Math.pow(2, 31);
        
        
        if (n == 1) {
            return true;
        }
        
        // Search from both directions (0->max_int), (max_int->0)
        while ((p <= n) & (q >= n)) {
            p *= 2;
            q /= 2;
        }
        
        
        if ((p/2 == n) | (q*2 == n)) {
            return true;
        }else {
            return false;
        }

    }
}