class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        int exp = 0;
        
        for (int i = 1; i <= num; i++) {
            if (i >= pow(2, exp + 1))    exp++;
            dp[i] = dp[i - pow(2, exp)] + 1;
        }
        
        return dp;
    }
};