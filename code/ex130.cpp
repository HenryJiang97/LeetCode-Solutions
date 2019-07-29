// DFS

class Solution {
    int m = 0, n = 0;
    
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();    if (m == 0)    return;
        n = board[0].size();    if (n == 0)    return;
        
        // To keep the char or change to X
        auto keep = vector<vector<bool>>(m, vector<bool>(n));
        
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !keep[i][0])    dfs(board, keep, i, 0);
            if (board[i][n - 1] == 'O' && !keep[i][n - 1])    dfs(board, keep, i, n - 1);
        }
        
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O' && !keep[0][i])    dfs(board, keep, 0, i);
            if (board[m - 1][i] == 'O' && !keep[m - 1][i])    dfs(board, keep, m - 1, i);
        }
        
        // Modify board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !keep[i][j])
                    board[i][j] = 'X';
            }
        }
        
        return;
    }
    
private:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& keep, int i, int j) {
        keep[i][j] = true;
        
        // Go four directions
        if (i + 1 < m && board[i + 1][j] == 'O' && !keep[i + 1][j])    dfs(board, keep, i + 1, j);
        if (i - 1 >= 0 && board[i - 1][j] == 'O' && !keep[i - 1][j])    dfs(board, keep, i - 1, j);
        if (j + 1 < n && board[i][j + 1] == 'O' && !keep[i][j + 1])    dfs(board, keep, i, j + 1);
        if (j - 1 >= 0 && board[i][j - 1] == 'O' && !keep[i][j - 1])    dfs(board, keep, i, j - 1);
    }
};