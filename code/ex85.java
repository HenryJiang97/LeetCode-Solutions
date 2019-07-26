class Solution {
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;    if (m == 0)    return 0;
        int n = matrix[0].length;    if (n == 0)    return 0;
        
        // Max length before column i in a row
        int[][] maxlen = new int[m][n];
        for (int i = 0; i < m; i++) {
            maxlen[i][0] = matrix[i][0] - '0';
            for (int j = 1; j < n; j++) {
                maxlen[i][j] = matrix[i][j] == '1' ? maxlen[i][j - 1] + 1 : 0;
            }
        }
        
        int max = 0;
        for (int col = 0; col < n; col++) {
            for (int row = 0; row < m; row++) {
                if (maxlen[row][col] == 0)    continue;
                int minlen = maxlen[row][col], width = 1;
                max = Math.max(max, minlen);
                
                for (int r = row + 1; r < m; r++) {
                    if (maxlen[r][col] == 0)    break;
                    
                    width++;
                    minlen = Math.min(minlen, maxlen[r][col]);
                    max = Math.max(max, minlen * width);
                }
            }
        }
        
        return max;
    }
}