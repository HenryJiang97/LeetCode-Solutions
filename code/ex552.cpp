// DP

class Solution {
public:
    int checkRecord(int n) {
        int mod = 1e9 + 7;
        
        long dp00[n + 1] = {0};    // Has no 'A' and ends with no 'L'
        long dp01[n + 1] = {0};    // Has no 'A' and ends with one 'L'
        long dp02[n + 1] = {0};    // Has no 'A' and ends with two continuous 'L'
        
        long dp10[n + 1] = {0};    // Has one 'A' and ends with no 'L' 
        long dp11[n + 1] = {0};    // Has one 'A' and ends with one 'L'
        long dp12[n + 1] = {0};    // Has one 'A' and ends with two continuous 'L'
        
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
};