const int dir[3][2] = {{1, 0}, {0, 1}, {1, 1}};
const int mod = 1e9 + 7;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size(), n = board[0].length();
        board[0][0] = '0';
        
        vector<vector<int>> maxSum(m, vector<int>(n));
        vector<vector<int>> cnt(m, vector<int>(n));
        maxSum[m - 1][n - 1] = 0;    cnt[m - 1][n - 1] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && n == n - 1 || board[i][j] == 'X')    continue;
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || cnt[ni][nj] == 0)
                        continue;
                    if (maxSum[ni][nj] + (board[i][j] - '0') > maxSum[i][j]) {
                        maxSum[i][j] = maxSum[ni][nj] + (board[i][j] - '0');
                        cnt[i][j] = cnt[ni][nj];
                    } else if (maxSum[ni][nj] + (board[i][j] - '0') == maxSum[i][j]) {
                        cnt[i][j] = (cnt[i][j] + cnt[ni][nj]) % mod;
                    }
                }
            }
        }
        
        return {maxSum[0][0], cnt[0][0]};
    }
};