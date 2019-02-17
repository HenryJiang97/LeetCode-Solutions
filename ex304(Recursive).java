class NumMatrix {
    private static int[][] sum;
    
    private static int sum_cal(int[][] matrix, int i, int j) {
        if (i == 0 || j == 0)   return 0;
        
        sum[i][j] = sum_cal(matrix, i - 1, j) + sum_cal(matrix, i, j - 1) - sum_cal(matrix, i - 1, j - 1) + matrix[i - 1][j - 1];
        return sum[i][j];
    }
    
    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            sum = new int[0][0];
            return;
        }
        
        sum = new int[matrix.length + 1][matrix[0].length + 1];
        
        for (int i = 0; i <= matrix.length; i++)    sum[i][0] = 0;
        for (int j = 0; j <= matrix[0].length; j++)    sum[0][j] = 0;
        
        sum[matrix.length][matrix[0].length] = sum_cal(matrix, matrix.length - 1, matrix[0].length) + sum_cal(matrix, matrix.length, matrix[0].length - 1) - sum_cal(matrix, matrix.length - 1, matrix[0].length - 1) + matrix[matrix.length - 1][matrix[0].length - 1];
        
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }
}