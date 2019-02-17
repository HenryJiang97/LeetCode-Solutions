
class Solution {
    public int maximalRectangle(char[][] matrix) {
        int result = 0;

        // Special situation
        if (matrix.length == 0 || matrix[0].length == 0)    return 0;
        
        int x = matrix.length;
        int y = matrix[0].length;
        
        if (x == 0 || y == 0)    return 0;
        
        int[][] row_max_matrix = new int[x][y];
        
        // Build row_max array
        for (int i = 0; i < x; i++) {
            row_max_matrix[i][y-1] = (matrix[i][y-1] == '1') ? 1 : 0;
            for (int j = y-2; j >= 0; j--) {
                if (matrix[i][j] == '0')    row_max_matrix[i][j] = 0;
                else    row_max_matrix[i][j] = row_max_matrix[i][j + 1] + 1;
            }
        }
        
        // Traverse through columns
        int row, col;
        int rectangle_max = 0;
        int row_max_c, rows;
        int calc;
        
        for (col = 0; col < y; col++)  {
        	for (row = 0; row < x; row++)  {
        		if ((x-row) * (y-col) < result)  continue;  // Not possible to get a larger number
        		rectangle_max = 0;
        		row_max_c = y;
        		rows = 1;
        		for (int i = row; i < x; i++)  {
        			if (row_max_matrix[i][col] == 0)  break;
        			if (row_max_matrix[i][col] < row_max_c)  row_max_c = row_max_matrix[i][col];
        			calc = row_max_c * rows;
        			if (rectangle_max < calc)	rectangle_max = calc;
        			rows ++;
        		}
        		if (result < rectangle_max)  result = rectangle_max;
        	}
        }
        
        return result;
    }
}