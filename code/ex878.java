class Solution {
    public int nthMagicalNumber(int N, int A, int B) {
        int mod = (int)1e9 + 7;
        long LCM = (long)(A * B) / GCD(A, B);
        
        long lo = 0, hi = (long)1e18;
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            long n = mid / A + mid / B - mid / LCM;
            if (n < N)
                lo = mid + 1;
            else
                hi = mid;
        }
        
        return (int)(hi % mod);
    }
    
    private int GCD(int a, int b) {
        int k = b;
        while (b != 0) {
            k = b;
            b = a % b;
            a = k;
        }
        return a;
    }
}