class TicTacToe {
    vector<vector<int>> board;
    int n;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        board = vector<vector<int>>(n, vector<int>(n));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        return win();
    }
    
private:
    int win() {
        // Row
        for (int i = 0; i < n; i++) {
            bool ifWin = 1;
            int val = board[i][0];
            if (val == 0)    continue;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != val) {
                    ifWin = 0;
                    break;
                }
            }
            if (ifWin)    return val;
        }
        
        // Col
        for (int j = 0; j < n; j++) {
            bool ifWin = 1;
            int val = board[0][j];
            if (val == 0)    continue;
            for (int i = 0; i < n; i++) {
                if (board[i][j] != val) {
                    ifWin = 0;
                    break;
                }
            }
            if (ifWin)    return val;
        }
        
        // Diagonal 1
        bool ifWin = 1;
        int val = board[0][0];
        if (val != 0) {
            for (int i = 0; i < n; i++) {
                if (board[i][i] != val) {
                    ifWin = 0;
                    break;
                }
            }
            if (ifWin)    return val;
        }
        
        // Diagonal 2
        ifWin = 1;
        val = board[n - 1][0];
        if (val != 0) {
            for (int i = n - 1; i >= 0; i--) {
                if (board[i][n - i - 1] != val) {
                    ifWin = 0;
                    break;
                }
            }
            if (ifWin)    return val;
        }
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */