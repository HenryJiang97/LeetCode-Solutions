class Solution {   
    public static int DFS(int[][] matrix, int i, int j, int l, int max, int m) {
        // Cannot be larger than max, no need to go further
        if (m - l <= max - l) {
            return max;
        }
        
        // Go left
        if (j > 0 && matrix[i][j - 1] > matrix[i][j])
            max = DFS(matrix, i, j - 1, l + 1, max, m);
        
        // Go right
        if (j < matrix[0].length - 1 && matrix[i][j + 1] > matrix[i][j])
            max = DFS(matrix, i, j + 1, l + 1, max, m);
    
        // Go up
        if (i > 0 && matrix[i - 1][j] > matrix[i][j])
            max = DFS(matrix, i - 1, j, l + 1, max, m);
        
        // Go down
        if (i < matrix.length - 1 && matrix[i + 1][j] > matrix[i][j])
            max = DFS(matrix, i + 1, j, l + 1, max, m);
        
        // Cannot go further
        max = Math.max(max, l);
        
            
        return max;
    }
    
    public int longestIncreasingPath(int[][] matrix) {
        int max = 0;
        int m = Integer.MIN_VALUE;
        
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[0].length; j++)
                m = Math.max(m, matrix[i][j]);

        
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[0].length; j++)
                max = DFS(matrix, i, j, 1, max, m);
    
        
        return max;
    }
}