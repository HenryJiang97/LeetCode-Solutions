const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
    int m, n;
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();    if (m == 0)    return;
        n = board[0].size();    if (n == 0)    return;
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 && j != 0 && i != m - 1 && j != n - 1)
                    continue;
                if (visited[i][j] || board[i][j] == 'X')    continue;
                visited[i][j] = 1;
                board[i][j] = 'K';
                dfs(board, visited, i, j);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'K')    board[i][j] = 'O';
                else if (board[i][j] == 'O')    board[i][j] = 'X';
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
        for (auto d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj] || board[ni][nj] == 'X')
                continue;
            visited[ni][nj] = 1;
            board[ni][nj] = 'K';
            dfs(board, visited, ni, nj);
        }
    }
};