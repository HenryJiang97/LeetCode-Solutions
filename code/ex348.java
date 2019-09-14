class TicTacToe {
    public class state { 
        int n1 = 0;    // Num of player1 on the line
        int n2 = 0;    // Num of player2 on the line
        boolean mayWin = true;    // If the line can win any more
    }
    
    public state[] r;
    public state[] c;
    public state diag1;
    public state diag2;
    public int n;
    
    /** Initialize your data structure here. */
    public TicTacToe(int n) {
        r = new state[n];
        c = new state[n];
        for (int i = 0; i < n; i++) {
            r[i] = new state();
            c[i] = new state();
        }
        
        diag1 = new state();
        diag2 = new state();
        this.n = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    public int move(int row, int col, int player) {
        if (row == col) {    // Diag1
            if (player == 1) {
                if (++diag1.n1 == n && diag1.mayWin)    return 1;
            }
            if (player == 2) {
                if (++diag1.n2 == n && diag1.mayWin)    return 2;
            }
            if (diag1.n1 != 0 && diag1.n2 != 0)    diag1.mayWin = false;
        }
        
        if (row + col == n - 1) {    // Diag2
            if (player == 1) {
                if (++diag2.n1 == n && diag2.mayWin)    return 1;
            }
            if (player == 2) {
                if (++diag2.n2 == n && diag2.mayWin)    return 2;
            }
            if (diag2.n1 != 0 && diag2.n2 != 0)    diag2.mayWin = false;
        }
        
        // Row
        if (player == 1) {
            if (++r[row].n1 == n)    return 1;
        }
        if (player == 2) {
            if (++r[row].n2 == n)    return 2;
        }
        if (r[row].n1 != 0 && r[row].n2 != 0)    r[row].mayWin = false;
        
        // Col
        if (player == 1) {
            if (++c[col].n1 == n)    return 1;
        }
        if (player == 2) {
            if (++c[col].n2 == n)    return 2;
        }
        if (c[col].n1 != 0 && c[col].n2 != 0)    c[col].mayWin = false;
        
        return 0;
    }
}

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */