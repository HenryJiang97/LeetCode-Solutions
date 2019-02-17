class NumMatrix {
    private static int[][] sum;
    
    public NumMatrix(int[][] matrix) {
        // Special situation
        if (matrix.length == 0 || matrix[0].length == 0)    return;
        
        sum = new int[matrix.length][matrix[0].length + 1];
        
        for (int i = 0; i < matrix.length; ++i)
            for (int j = 1; j <= matrix[0].length; ++j)
                sum[i][j] = sum[i][j - 1] + matrix[i][j - 1];
        
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int s = 0;
            
        for (int i = row1; i <= row2; i++)
            s += sum[i][col2 + 1] - sum[i][col1];
        
        return s;
    }
}