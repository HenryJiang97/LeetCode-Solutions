// 0 => dead
// 1 => alive
// 2 => dead -> alive
// 3 => alive -> dead

const int dir[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int alive = 0;
                
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                    if (board[ni][nj] == 1 || board[ni][nj] == 3)    alive++;
                }
                
                if (board[i][j] == 1 && alive < 2)    board[i][j] = 3;
                if (board[i][j] == 1 && alive > 3)    board[i][j] = 3;
                if (board[i][j] == 0 && alive == 3)    board[i][j] = 2;
            }
        }
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = board[i][j] == 0 || board[i][j] == 3 ? 0 : 1;
    }
};