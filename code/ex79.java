class Solution {
    public int m = 0, n = 0;
    
    public boolean exist(char[][] board, String word) {
        if (word.length() == 0)    return true;
        m = board.length;    if (m == 0)    return false;
        n = board[0].length;
        
        boolean[][] visited = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, visited, i, j))    return true;
            }
        }
        
        return false;
    }
    
    private boolean dfs(char[][] board, String word, boolean[][] visited, int i, int j) {
        if (word.length() == 1)    return word.charAt(0) == board[i][j] ? true : false;
        if (board[i][j] != word.charAt(0))    return false;
        
        char cur = word.charAt(0);
        visited[i][j] = true;
        
        boolean res = false;
        // Go four directions if possible
        // Go right
        if (j + 1 < n && !visited[i][j + 1])    res |= dfs(board, word.substring(1), visited, i, j + 1);
        if (res)    {visited[i][j] = false;    return true;}
        // Go down
        if (i + 1 < m && !visited[i + 1][j])    res |= dfs(board, word.substring(1), visited, i + 1, j);
        if (res)    {visited[i][j] = false;    return true;}
        // Go up
        if (i - 1 >= 0 && !visited[i - 1][j])    res |= dfs(board, word.substring(1), visited, i - 1, j);
        if (res)    {visited[i][j] = false;    return true;}
        // Go left
        if (j - 1 >= 0 && !visited[i][j - 1])    res |= dfs(board, word.substring(1), visited, i, j - 1);
        if (res)    {visited[i][j] = false;    return true;}
        
        
        visited[i][j] = false;
        
        return false;
    }
}