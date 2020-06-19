class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int na = A.size(), nb = B.size();
        
        vector<vector<int>> dp(na + 1, vector<int>(nb + 1));
        int MAX = 0;
        for (int i = 1; i <= na; i++) {
            for (int j = 1; j <= nb; j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                MAX = max(MAX, dp[i][j]);
            }
        }
        
        return MAX;
    }
};