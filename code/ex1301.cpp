class Solution {
    int dir[3][2] = {{-1, 0}, {0, -1}, {-1, -1}};
    int mod = 1e9 + 7;
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, INT_MIN / 2)));
        dp[m - 1][n - 1] = {0, 1};
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || board[ni][nj] == 'X')    continue;
                    int score = dp[i][j][0] + (board[ni][nj] == 'E' ? 0 : board[ni][nj] - '0');
                    if (score >= dp[ni][nj][0]) {
                        if (score > dp[ni][nj][0]) {
                            dp[ni][nj][0] = score;
                            dp[ni][nj][1] = 0;
                        }
                        dp[ni][nj][1] = (dp[ni][nj][1] + dp[i][j][1]) % mod;
                    }
                }
            }
        }
        return dp[0][0][0] < 0 ? vector<int>{0, 0} : dp[0][0];
    }
};