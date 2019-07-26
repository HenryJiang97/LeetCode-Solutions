// Dynamic Programming

class Solution {
    public int numTrees(int n) {      
        // Init dp array
        int dp[] = new int[n + 1];  
        dp[0] = 1;  
        
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                dp[i] += (dp[j - 0] * dp[i - 1 - j]);

        
        return dp[n];
    }
}