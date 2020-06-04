class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();    if (m == 0)    return {};
        int n = matrix[0].size();    if (n == 0)    return {};
        
        vector<int> res;
        int row = m - 1, col = n, i = 0, j = -1;
        while (row > 0 || col > 0) {
            for (int c = 1; c <= col; c++) {
                res.push_back(matrix[i][j + c]);
            }
            j += col;
            if (--col < 0)    break;
            
            for (int r = 1; r <= row; r++) {
                res.push_back(matrix[i + r][j]);
            }
            i += row;
            if (--row < 0)    break;
            
            for (int c = 1; c <= col; c++) {
                res.push_back(matrix[i][j - c]);
            }
            j -= col;
            if (--col < 0)    break;
            
            for (int r = 1; r <= row; r++) {
                res.push_back(matrix[i - r][j]); 
            }
            i -= row;
            if (--row < 0)    break;
        }
        
        return res;
    }
};