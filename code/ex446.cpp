class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)A[i] - (long long)A[j];
                if (diff >= INT_MAX || diff <= INT_MIN)    continue;
                int d = (int)diff;
                
                int dpj = dp[j].find(d) != dp[j].end() ? dp[j][d] : 0;
                cnt += dpj;
                dp[i][d] += dpj + 1;
            }
        }
        return cnt;
    }
};