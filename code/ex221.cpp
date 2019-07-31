// DP

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();    if (m == 0)    return 0;
        int n = matrix[0].size();    if (n == 0)    return 0;
        
        int MAX = 0;
        // Init dp array
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == '1') {
                dp[i][0] = 1;
                MAX = 1;
            }
            
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == '1') {
                dp[0][j] = 1;
                MAX = 1;
            }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != '1')    continue;   
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;        
                MAX = max(MAX, dp[i][j]);
            }
        }
        
        return MAX * MAX;
    }
};