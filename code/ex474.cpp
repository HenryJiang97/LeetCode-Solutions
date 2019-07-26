// Knapsack (DP)

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N = strs.size();
        auto arr = vector<vector<int>>(N + 1, vector<int>(2));
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < strs[i - 1].length(); j++) {
                if (strs[i - 1][j] == '0')    arr[i][0]++;
                else    arr[i][1]++;
            }
        }
        
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int a = 1; a <= N; a++) {
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (arr[a][0] <= i && arr[a][1] <= j) {
                        dp[a][i][j] = max(dp[a - 1][i][j], 1 + dp[a - 1][i - arr[a][0]][j - arr[a][1]]);
                    } else {
                        dp[a][i][j] = dp[a - 1][i][j];
                    }
                }
            }
        }
        
        return dp[N][m][n];
    }
};