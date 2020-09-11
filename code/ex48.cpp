class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Invert by diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                int ni = n - j - 1, nj = n - i - 1;
                swap(matrix[i][j], matrix[ni][nj]);
            }
        }
        
        // Invert each column
        for (int j = 0; j < n; j++) {
            int lo = 0, hi = n - 1;
            while (lo < hi) {
                swap(matrix[lo++][j], matrix[hi--][j]);
            }
        }
    }
};