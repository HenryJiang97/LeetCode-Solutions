class Solution {
    bool row[9][9] = {0};
    bool col[9][9] = {0};
    bool box[3][3][9] = {0};
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Initial state
        int cnt = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int val = (board[i][j] - '0') - 1;
                    row[i][val] = col[j][val] = box[i / 3][j / 3][val] = 1;
                }
            }
        }
        
        // DFS
        bool ret = dfs(board, 0, 0);
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if (i * 9 + j >= 81)    return 1;
        
        if (board[i][j] != '.') {
            return dfs(board, (i * 9 + j + 1) / 9, (i * 9 + j + 1) % 9);
        } else {
            for (int v = 1; v <= 9; v++) {
                if (row[i][v - 1] || col[j][v - 1] || box[i / 3][j / 3][v - 1])    continue;
                row[i][v - 1] = col[j][v - 1] = box[i / 3][j / 3][v - 1] = 1;
                board[i][j] = (char)('0' + v);
                    
                bool ret = dfs(board, (i * 9 + j + 1) / 9, (i * 9 + j + 1) % 9);
                if (ret)    return 1;
                
                board[i][j] = '.';
                row[i][v - 1] = col[j][v - 1] = box[i / 3][j / 3][v - 1] = 0;
            }
        }
        
        return 0;
    }
};