class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();    if (m == 0)    return 0;
        int n = matrix[0].size();    if (n == 0)    return 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int MAX = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i - 1][j - 1] == '0')    continue;
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                MAX = max(MAX, dp[i][j]);
            }
        }
        return MAX * MAX;
    }
};