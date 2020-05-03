class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();    if (n == 0)    return 0;

        // The maximum points removing boxes between i and j with k continuous boxes on the left
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));

        for (int i = 0; i < n; i++)
            for (int k = 0; k <= i; k++)
                dp[i][i][k] = (k + 1) * (k + 1);

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                for (int k = 0; k <= i; k++) {
                    dp[i][j][k] = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for (int m = i + 1; m <= j; m++) {
                        if (boxes[m] == boxes[i]) {
                            dp[i][j][k] = max(dp[i][j][k], dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                        }
                    }
                }
            }
        }

        return dp[0][n - 1][0];
    }
};