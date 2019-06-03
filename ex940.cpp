// DP
// dp[i] = 2 * dp[i - 1] - duplicate
// duplicate = dp[(index of last appearance of S[i]) - 1]

class Solution {
public:
    int distinctSubseqII(string S) {
        int n = S.length();
        if (n == 0)    return 0;
        int mod = 1e9 + 7;
        
        // Init dp
        vector<int> dp(n);
        dp[0] = 2;
        
        // Build dp
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] * 2 % mod;
            
            // Calculate the duplicate
            int j = i - 1;
            while (j >= 0 && S[j] != S[i])    j--;
            j--;
            if (j >= 0)    dp[i] -= dp[j];
            else if (j == -1)    dp[i] -= 1;
            
            dp[i] %= mod;
        }
        
        if (dp[n - 1] - 1 < 0)    return mod + dp[n - 1] - 1;
        
        return dp[n - 1] - 1;
    }
};

