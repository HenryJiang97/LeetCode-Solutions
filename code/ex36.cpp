class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row
        for (int i = 0; i < 9; i++) {
            unordered_set<int> set;
            for (int j = 0; j < 9; j++) {
                if (set.count(board[i][j]) > 0)    return 0;
                if (board[i][j] != '.')    set.insert(board[i][j]);
            }
        }
        
        // Col
        for (int j = 0; j < 9; j++) {
            unordered_set<int> set;
            for (int i = 0; i < 9; i++) {
                if (set.count(board[i][j]) > 0)    return 0;
                if (board[i][j] != '.')    set.insert(board[i][j]);
            }
        }
        
        // Grid
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!judgeGrid(board, i, j))    return 0;
            }
        }
        
        return 1;
    }
    
private:
    // Judge Grid
    bool judgeGrid(vector<vector<char>>& board, int si, int sj) {
        unordered_set<int> set;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (set.count(board[si + i][sj + j]) > 0)    return 0;
                if (board[si + i][sj + j] != '.')    set.insert(board[si + i][sj + j]);
            }
        }
        return 1;
    }
};