class Solution {
    public int m, n;
    
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        m = image.length;    if (m == 0)    return image;
        n = image[0].length;    if (n == 0)    return image;
        
        boolean[][] visited = new boolean[m][n];
        dfs(image, sr, sc, newColor, image[sr][sc], visited);
        
        return image;
    }
    
    private void dfs(int[][] image, int x, int y, int newColor, int oldColor, boolean[][] visited) {
        visited[x][y] = true;
        image[x][y] = newColor;
        
        // Go four directions
        // Left
        if (y - 1 >= 0 && !visited[x][y - 1] && image[x][y - 1] == oldColor)
            dfs(image, x, y - 1, newColor, oldColor, visited);
        
        // Right
        if (y + 1 < n && !visited[x][y + 1] && image[x][y + 1] == oldColor)
            dfs(image, x, y + 1, newColor, oldColor, visited);
        
        // Up
        if (x - 1 >= 0 && !visited[x - 1][y] && image[x - 1][y] == oldColor)
            dfs(image, x - 1, y, newColor, oldColor, visited);
        
        // Down
        if (x + 1 < m && !visited[x + 1][y] && image[x + 1][y] == oldColor)
            dfs(image, x + 1, y, newColor, oldColor, visited);
        
        
    }
}