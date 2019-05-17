class Solution {
    public int findKthNumber(int n, int k) {
        int res = 1;
        
        while (k > 1) {
            // Get the number of integers between res and res + 1
            int cnt = cntNum(res, res + 1, n);
            
            if (cnt < k) {
                // Go to next num having the same length of digit
                res++;
                k -= cnt;
            } else {
                // Result must between res and res + 1, extend the length of res
                k--;
                res *= 10;
            }
        }
        
        return res;
    }
    
    
    // Get the total number of nums between p and q
    private int cntNum(long p, long q, long n) {
        int res = 0;
        
        while (p <= n) {
            res += Math.min(q, n + 1) - p;
            p *= 10;    q *= 10;
        }
        
        return res;
    }
    
}