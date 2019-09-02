class Solution {
    public int m, n;
    
    public void solve(char[][] board) {
        m = board.length;    if (m == 0)    return;
        n = board[0].length;    if (n == 0)    return;
        
        boolean[][] notFlip = new boolean[m][n];
        
        // DFS through the top and bottom row
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O')    dfs(board, notFlip, 0, i);
            if (board[m - 1][i] == 'O')    dfs(board, notFlip, m - 1, i);
        }
        
        // DFS through the left most and right most column
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O')    dfs(board, notFlip, i, 0);
            if (board[i][n - 1] == 'O')    dfs(board, notFlip, i, n - 1);
        }
        
        // Flip inner 'O's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!notFlip[i][j])    board[i][j] = 'X';
            }
        }
    }
    
    private void dfs(char[][] board, boolean[][] notFlip, int i, int j) {
        notFlip[i][j] = true;
        
        // Go four directions
        
        // Go down
        if (i + 1 < m && !notFlip[i + 1][j] && board[i + 1][j] == 'O')
            dfs(board, notFlip, i + 1, j);
        
        // Go up
        if (i - 1 >= 0 && !notFlip[i - 1][j] && board[i - 1][j] == 'O')
            dfs(board, notFlip, i - 1, j);
        
        // Go left
        if (j - 1 >= 0 && !notFlip[i][j - 1] && board[i][j - 1] == 'O')
            dfs(board, notFlip, i, j - 1);
        
        // Go down
        if (j + 1 < n && !notFlip[i][j + 1] && board[i][j + 1] == 'O')
            dfs(board, notFlip, i, j + 1);
    }
}