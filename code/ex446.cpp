class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        
        int cnt = 0;
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = (long long)A[i] - (long long)A[j];
                if (d >= INT_MAX || d <= INT_MIN)    continue;
                int diff = (int)d;
                
                if (dp[j].find(diff) != dp[j].end()) {
                    cnt += dp[j][diff];
                    dp[i][diff] += dp[j][diff] + 1;
                } else
                    dp[i][diff]++;
            }
        }
        
        return cnt;
    }
};