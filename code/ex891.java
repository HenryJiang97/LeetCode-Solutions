class Solution {
    public final int mod = (int)1e9 + 7;
    public int sumSubseqWidths(int[] A) {
        int n = A.length;
        Arrays.sort(A);
        
        // Calculate power of 2 in advance and do mod
        long[] pow2 = new long[20001];
        pow2[0] = 1;
        for (int i = 1; i <= 20000; i++)
            pow2[i] = (pow2[i - 1] * 2) % mod;
        
        // sum(A[j] - A[i]) = sum(A[j]) - sum(A[i])  // j > i
        long res = 0;
        for (int i = 0; i < n; i++) {
            res = (res + A[i] * pow2[i]) % mod;
            res = (res - A[i] * pow2[n - i - 1]) % mod;
        }    
        return (int)res;
    }
}