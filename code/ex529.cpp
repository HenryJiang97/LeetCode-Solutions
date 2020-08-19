class Solution {
    const int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int m, n;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();    n = board[0].size();
        int ci = click[0], cj = click[1];
        if (board[ci][cj] == 'M') {
            board[ci][cj] = 'X';
            return board;
        }
        dfs(board, ci, cj);
        return board;
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'B';
        int mine = getMine(board, i, j);
        if (mine > 0)    board[i][j] = (char)('0' + mine);
        else {
            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n || board[ni][nj] != 'E')    continue;
                dfs(board, ni, nj);
            }
        }
    }
    
    int getMine(vector<vector<char>>& board, int i, int j) {
        int cnt = 0;
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
            if (board[ni][nj] == 'M')    cnt++;
        }
        return cnt;
    }
};