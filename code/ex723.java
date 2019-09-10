class Solution {    
    public int[][] candyCrush(int[][] board) {
        int m = board.length, n = board[0].length;
        
        boolean ifChanges = false;
        // Mark candies need to be crushed horizontally
        for (int i = 0; i < m; i++) {
            int head = 0, end = 1, num = Math.abs(board[i][head]), cnt = 0;
            while (end < n) {
                if (Math.abs(board[i][end]) == num)    end++;
                else {
                    if (end - head >= 3 && num != 0) {
                        for (int j = head; j < end; j++)    // Mark the interval need to be crushed
                            board[i][j] = -Math.abs(board[i][j]);
                        ifChanges = true;
                    }
                    
                    head = end;    end++;    num = Math.abs(board[i][head]);
                }
            }
            
            if (end - head >= 3 && num != 0) {    // End interval
                for (int j = head; j < end; j++)    // Mark the interval need to be crushed
                    board[i][j] = -Math.abs(board[i][j]);
                ifChanges = true;
            }
        }
        
        // Mark candies need to be crushed vertically
        for (int j = 0; j < n; j++) {
            int head = 0, end = 1, num = Math.abs(board[head][j]), cnt = 0;
            while (end < m) {
                if (Math.abs(board[end][j]) == num)    end++;
                else {
                    if (end - head >= 3 && num != 0) {
                        for (int i = head; i < end; i++)    // Mark the interval need to be crushed
                            board[i][j] = -Math.abs(board[i][j]);
                        ifChanges = true;
                    }
                    
                    head = end;    end++;    num = Math.abs(board[head][j]);
                }
            }
            
            if (end - head >= 3 && num != 0) {
                for (int i = head; i < end; i++)    // Mark the interval need to be crushed
                    board[i][j] = -Math.abs(board[i][j]);
                ifChanges = true;
            }
        }
        
        
        if (ifChanges) {
            // Crush candies (set marked points to zero)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    if (board[i][j] < 0)
                        board[i][j] = 0;
            
            
            // Realign the board (dropping)
            for (int j = 0; j < n; j++) {
                int p1 = m - 1, p2 = m - 1;
                while (p2 >= 0) {
                    if (board[p2][j] != 0) {
                        board[p1--][j] = board[p2--][j];
                    } else {
                        p2--;
                    }
                }
                while (p1 >= 0)    board[p1--][j] = 0;
            }
        }
        
        return ifChanges ? candyCrush(board) : board;
    }
}