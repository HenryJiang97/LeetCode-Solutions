class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n = A.size();
        
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        int MAX = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = A[i] - A[j];
                if (dp[j].find(diff) == dp[j].end())
                    dp[i][diff] = 2;
                else
                    dp[i][diff] = dp[j][diff] + 1;
                MAX = max(MAX, dp[i][diff]);
            }
        }
        
        return MAX;
    }
};