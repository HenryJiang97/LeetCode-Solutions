class Solution {
    private int[] dp;
    
    private int recur(int N) {
        if (dp[N] != -1)    return dp[N];
        
        int a = recur(N - 1) + recur(N - 2);
        dp[N] = a;
        
        return dp[N];
    }
    
    public int fib(int N) {
        if (N == 0)    return 0;
        
        dp = new int[N + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;    dp[1] = 1;
        
        return recur(N);
    }
}