class Solution {
    public int checkRecord(int n) {
        long mod = (long)Math.pow(10, 9) + 7;
        
        // Define dp arrays
        long[] dp00 = new long[n + 1];  // 'A' never appeared till n, ending with no 'L'
        long[] dp01 = new long[n + 1];  // 'A' never appeared till n, ending with one 'L'
        long[] dp02 = new long[n + 1];  // 'A' never appeared till n, ending with two 'L'
        long[] dp10 = new long[n + 1];  // 'A' appeared once till n, ending with no 'L'
        long[] dp11 = new long[n + 1];  // 'A' appeared once till n, ending with one 'L'
        long[] dp12 = new long[n + 1];  // 'A' appeared once till n, ending with two 'L'

        // Init dp arrays
        dp00[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp00[i] = (dp00[i - 1] + dp01[i - 1] + dp02[i - 1]) % mod;
            dp01[i] = dp00[i - 1];
            dp02[i] = dp01[i - 1];
            
            dp10[i] = (dp00[i - 1] + dp01[i - 1] + dp02[i - 1] + dp10[i - 1] + dp11[i - 1] + dp12[i - 1]) % mod;
            dp11[i] = dp10[i - 1];
            dp12[i] = dp11[i - 1];
        }
        
        return (int)((dp00[n] + dp01[n] + dp02[n] + dp10[n] + dp11[n] + dp12[n]) % mod);
    }
}