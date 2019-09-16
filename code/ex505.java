// DFS

class Solution {
    private int m, n;
    
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {
        m = maze.length;    n = maze[0].length;
        
        int[][] dp = new int[m][n];
        dfs(maze, dp, destination, start[0], start[1], 1);

        return dp[destination[0]][destination[1]] == 0 ? -1 : dp[destination[0]][destination[1]] - 1;
    }
    
    private void dfs(int[][] maze, int[][] dp, int[] destination, int i, int j, int step) {
        if (i == destination[0] && j == destination[1]) {
            dp[i][j] = step;
            return;
        }
        
        int newI = i, newJ = j;
        dp[i][j] = step;
        
        // Fo four directions
        // Go left
        newI = i;    newJ = j;
        while (newJ - 1 >= 0 && maze[i][newJ - 1] == 0)    newJ--;
        if (dp[i][newJ] == 0 || dp[i][j] + j - newJ < dp[i][newJ])
            dfs(maze, dp, destination, i, newJ, dp[i][j] + j - newJ);

        // Go right
        newI = i;    newJ = j;
        while (newJ + 1 < n && maze[i][newJ + 1] == 0)    newJ++;
        if (dp[i][newJ] == 0 || dp[i][j] + newJ - j < dp[i][newJ])
            dfs(maze, dp, destination, i, newJ, dp[i][j] + newJ - j);

        
        // Go up
        newI = i;    newJ = j;
        while (newI - 1 >= 0 && maze[newI - 1][j] == 0)    newI--;
        if (dp[newI][j] == 0 || dp[i][j] + i - newI < dp[newI][j])
            dfs(maze, dp, destination, newI, j, dp[i][j] + i - newI);
 
        
        // Go down
        newI = i;    newJ = j;
        while (newI + 1 < m && maze[newI + 1][j] == 0)    newI++;
        if (dp[newI][j] == 0 || dp[i][j] + newI - i < dp[newI][j])
            dfs(maze, dp, destination, newI, j, dp[i][j] + newI - i);
    }
}