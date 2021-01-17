class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(5);
        for (int j = 0; j < 5; j++)    dp[j] = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> newDp(5);
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k <= j; k++) {
                    newDp[j] += dp[k];
                }
            }
            dp = newDp;
        }
        
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
            cnt += dp[j];
        }
        return cnt;
    }
};