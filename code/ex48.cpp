class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Flip by diagonal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Flip each row
        for (int i = 0; i < n; i++) {
            for (int lo = 0, hi = n - 1; lo < hi; ) {
                swap(matrix[i][lo++], matrix[i][hi--]);
            }
        }
    }
};