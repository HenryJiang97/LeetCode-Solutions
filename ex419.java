class Solution {
    public int countBattleships(char[][] board) {
        int cnt = 0;
        
        int[][] visited = new int[board.length][board[0].length];
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (visited[i][j] == 1)    continue;
                
                visited[i][j] = 1;
                
                // Mark visited node for battleships
                if (board[i][j] == 'X') {
                    cnt++;
                    
                    // Go right
                    if (j + 1 < board[0].length && board[i][j + 1] == 'X') {
                        dfs_right(board, visited, i, j + 1);
                    }
                    // Go down
                    if (i + 1 < board.length && board[i + 1][j] == 'X') {
                        dfs_down(board, visited, i + 1, j);
                    }
                }
            }
        }
        
        return cnt;
    }
    
    public void dfs_right(char[][] board, int[][] visited, int i, int j) {
        visited[i][j] = 1;
        // Go right
        if (j + 1 < board[0].length && board[i][j + 1] == 'X') {
            dfs_right(board, visited, i, j + 1);
        }
    }
    
    public void dfs_down(char[][] board, int[][] visited, int i, int j) {
        visited[i][j] = 1;
        // Go down
        if (i + 1 < board.length && board[i + 1][j] == 'X') {
            dfs_down(board, visited, i + 1, j);
        }
    }
}