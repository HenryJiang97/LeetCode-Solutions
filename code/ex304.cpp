// 2D-prefix sum

class NumMatrix {
    int m, n;
    vector<vector<int>> prefix;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();    if (m == 0)    return;
        n = matrix[0].size();    if (n == 0)    return;
        
        // Build 2D-prefix sum array for each row
        prefix = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for (int r = 1; r <= m; r++) {
            for (int c = 1; c <= n; c++) {
                prefix[r][c] = matrix[r - 1][c - 1] + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row1][col2 + 1] - prefix[row2 + 1][col1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */