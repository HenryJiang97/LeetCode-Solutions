class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;    if (m == 0)    return;
        int n = board[0].length;    if (n == 0)    return;
        
        // States:
        // 0: dead->dead
        // 1: live->live
        // 2: dead->live
        // 3: live->dead
        
        int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
         
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cnt = 0;
                
                // Search for eight directions
                for (int d = 0; d < 8; d++) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                    
                    if (board[ni][nj] == 1 || board[ni][nj] == 3)    cnt++;
                }
                
                // Live cell
                if (board[i][j] == 1 || board[i][j] == 3) {
                    // Case 1
                    if (cnt < 2)    board[i][j] = 3;
                    else if (cnt == 2 || cnt == 3)    board[i][j] = 1;
                    else    board[i][j] = 3;
                }
                // Dead cell
                else if (cnt == 3)    board[i][j] = 2;
            }
        }
        
        // Changes state sign to 1 and 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0 || board[i][j] == 3)    board[i][j] = 0;
                else    board[i][j] = 1;
            }
        }
    }
}