// BFS

class Solution {
    public int m, n;
    
    public int snakesAndLadders(int[][] board) {
        m = board.length; n = board[0].length;
        
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(1);
        
        boolean[] visited = new boolean[m * n + 1];
        int step = 0;
        while (!queue.isEmpty()) {
            for (int z = queue.size(); z > 0; z--) {    // Loop through current layer
                int out = queue.poll();    if (out == m * n)    return step;
                
                int[] corrdinate = corConvertor(out);
                int row = corrdinate[0], col = corrdinate[1];
                
                for (int i = 1; i <= 6; ++i) {    // Six ways to move forward
                    if (out + i > m * n)    continue;
                    
                    int[] newCor = corConvertor(out + i);
                    int newRow = newCor[0], newCol = newCor[1];
                    
                    if (board[newRow][newCol] != -1) {
                        if (visited[board[newRow][newCol]])    continue;
                        visited[board[newRow][newCol]] = true;
                        queue.offer(board[newRow][newCol]);
                    }
                    else {
                        if (visited[out + i])    continue;
                        visited[out + i] = true;
                        queue.offer(out + i);
                    }
                }
            }
            step++;
        }

        return -1;
    }
    
    private int[] corConvertor(int num) {    // Convert num to 2D corrdinate
        int row = m - 1 - (num - 1) / n;
        int col = (m - 1 - row) % 2 == 0 ? (num - 1) % n : n - (num - 1) % n - 1;
        return new int[]{row, col};
    }
}