class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        dp[0] = 0;
        int exp = 0;
        
        for (int i = 1; i <= num; i++) {
            if (i - pow(2, exp + 1) >= 0)
                exp++;
            int gap = pow(2, exp);
            dp[i] = dp[i - gap] + 1;
        }
        
        return dp;
    }
};