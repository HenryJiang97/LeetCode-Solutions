// DFS

import java.util.*;

class Solution {
    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new ArrayList<>();
        
        // Special cases
        if (matrix.length == 0)    return res;
        if (matrix[0].length == 0)    return res;
        
        boolean[][] pacific = new boolean[matrix.length][matrix[0].length];
        boolean[][] atlantic = new boolean[matrix.length][matrix[0].length];
        
        // DFS from pacific boundary
        for (int i = 0; i < matrix.length; i++) {
            dfs_pacific(matrix, pacific, i, 0);
        }
        
        for (int j = 0; j < matrix[0].length; j++) {
            dfs_pacific(matrix, pacific, 0, j);
        }
        
        // DFS from atlantic boundary
        for (int i = 0; i < matrix.length; i++) {
            dfs_atlantic(matrix, atlantic, i, matrix[0].length - 1);
        }
        
        for (int j = 0; j < matrix[0].length; j++) {
            dfs_atlantic(matrix, atlantic, matrix.length - 1, j);
        }
        
        // Get the result from those points where both pacific and atlantic is true
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    int[] r = new int[2];
                    r[0] = i;    r[1] = j;
                    res.add(r);
                }
            }
        }
        
        return res;
    }
    
    public void dfs_pacific(int[][] matrix, boolean[][] pacific, int i, int j) {
        pacific[i][j] = true;
        
        // Go left
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j] && !pacific[i][j - 1]) {
            dfs_pacific(matrix, pacific, i, j - 1);
        }
        // Go right
        if (j + 1 < matrix[0].length && matrix[i][j + 1] >= matrix[i][j] && !pacific[i][j + 1]) {
            dfs_pacific(matrix, pacific, i, j + 1);
        }
        // Go up
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j] && !pacific[i - 1][j]) {
            dfs_pacific(matrix, pacific, i - 1, j);
        }
        // Go down
        if (i + 1 < matrix.length && matrix[i + 1][j] >= matrix[i][j] && !pacific[i + 1][j]) {
            dfs_pacific(matrix, pacific, i + 1, j);
        }
    }
    
    public void dfs_atlantic(int[][] matrix, boolean[][] atlantic, int i, int j) {
        atlantic[i][j] = true;
        
        // Go left
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j] && !atlantic[i][j - 1]) {
            dfs_atlantic(matrix, atlantic, i, j - 1);
        }
        // Go right
        if (j + 1 < matrix[0].length && matrix[i][j + 1] >= matrix[i][j] && !atlantic[i][j + 1]) {
            dfs_atlantic(matrix, atlantic, i, j + 1);
        }
        // Go up
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j] && !atlantic[i - 1][j]) {
            dfs_atlantic(matrix, atlantic, i - 1, j);
        }
        // Go down
        if (i + 1 < matrix.length && matrix[i + 1][j] >= matrix[i][j] && !atlantic[i + 1][j]) {
            dfs_atlantic(matrix, atlantic, i + 1, j);
        }
    }
}