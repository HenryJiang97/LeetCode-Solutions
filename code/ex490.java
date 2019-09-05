// DFS

class Solution {
    public int m, n;
    
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        m = maze.length;    n = maze[0].length;
        
        boolean[][] visited = new boolean[m][n];
        
        return dfs(maze, start, destination, visited);
    }
    
    private boolean dfs(int[][] maze, int[] start, int[] destination, boolean[][] visited) {
        if (start[0] == destination[0] && start[1] == destination[1])    return true;
        
        visited[start[0]][start[1]] = true;
        
        boolean res = false;
        // Try to go four directions
        // Go down
        int i = start[0], j = start[1];
        while (i + 1 < m && maze[i + 1][j] == 0)    i++;
        if (!visited[i][j])    res |= dfs(maze, new int[]{i, j}, destination, visited);
        
        // Go up
        i = start[0]; j = start[1];
        while (i - 1 >= 0 && maze[i - 1][j] == 0)    i--;
        if (!visited[i][j])    res |= dfs(maze, new int[]{i, j}, destination, visited);
        
        // Go left
        i = start[0]; j = start[1];
        while (j - 1 >= 0 && maze[i][j - 1] == 0)    j--;
        if (!visited[i][j])    res |= dfs(maze, new int[]{i, j}, destination, visited);
        
        // Go right
        i = start[0]; j = start[1];
        while (j + 1 < n && maze[i][j + 1] == 0)    j++;
        if (!visited[i][j])    res |= dfs(maze, new int[]{i, j}, destination, visited);
        
        return res;
    }
}