class Solution {
    public int maximalRectangle(char[][] matrix) {
        // Special situation
        if (matrix.length == 0 || matrix[0].length == 0)    return 0;
        
        int result = 0;
        int row = matrix.length;
        int col = matrix[0].length;
        
        // Build row_max array
        int[][] row_max = new int[row][col];
        for (int i = 0; i < row; i++) {
            row_max[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '0')    row_max[i][j] = 0;
                else    row_max[i][j] = row_max[i][j - 1] + 1;
            }
        }
        
        
        // Traverse through columns
        int continuous = 0;
        int min, max;

        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                if (row_max[i][j] == 0)    continue;
                
                continuous = 1;
                min = col;    max = 0;
                
                for (int k = i; k < row; k++) {
                    if (row_max[k][j] == 0)    break;
                    
                    min = Math.min(min, row_max[k][j]);
                    max = Math.max(max, min * continuous);
                    
                    continuous++;
                }
                result = Math.max(result, max);
            }
        }
        
        return result;
    }
}