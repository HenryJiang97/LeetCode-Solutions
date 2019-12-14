class Solution {
    public boolean isValidSudoku(char[][] board) {
        // Judge rows
        for (int i = 0; i < 9; i++) {
            Set<Character> set = new HashSet<>();
            for (int j = 0; j < 9; j++) {
                if (!ifCharValid(board[i][j]) || set.contains(board[i][j]))    return false;
                if (board[i][j] != '.')    set.add(board[i][j]);
            }
        }
        
        // Judge columns
        for (int j = 0; j < 9; j++) {
            Set<Character> set = new HashSet<>();
            for (int i = 0; i < 9; i++) {
                if (!ifCharValid(board[i][j]) || set.contains(board[i][j]))    return false;
                if (board[i][j] != '.')    set.add(board[i][j]);
            }
        }
        
        // Judge grids
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                Set<Character> set = new HashSet<>();
                for (int r = i; r < i + 3; r++) {
                    for (int c = j; c < j + 3; c++) {
                        if (!ifCharValid(board[r][c]) || set.contains(board[r][c]))    return false;
                        if (board[r][c] != '.')    set.add(board[r][c]);
                    }
                }
            }
        }
        
        return true;
    }
    
    private boolean ifCharValid(char c) {
        return (c >= '1' && c <= '9') || c == '.';
    }
}