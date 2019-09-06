// BFS
// Time: O(m * n)

class Solution {
    public char[][] updateBoard(char[][] board, int[] click) {
        int m = board.length, n = board[0].length;
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        // BFS
        int[][] dir = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(click);
        
        while (!queue.isEmpty()) {
            int[] out = queue.poll();
            int x = out[0], y = out[1];
            if (board[x][y] != 'E')    continue;
            
            // Go eight directions for count of surrounding mines
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                int x1 = x + dir[i][0], y1 = y + dir[i][1];
                if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n)    continue;
                
                if (board[x1][y1] == 'M')    cnt++;
            }
            
            if (cnt != 0)    board[x][y] = (char)('0' + cnt);
            else
            {   // No adjacent mine found
                board[x][y] = 'B';
                
                // Add adjacent unrevealed squares to the queue
                for (int i = 0; i < 8; i++) {
                    int x1 = x + dir[i][0], y1 = y + dir[i][1];
                    if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n)    continue;

                    queue.offer(new int[]{x1, y1});
                }
            } 
        }
        
        return board;
    }
}