class Solution {
    int m, n;
public:
    int matrixScore(vector<vector<int>>& A) {
        m = A.size();    n = A[0].size();
        
        // For the first col
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                flipRow(A, i);
            }
        }
        
        // For rest cols
        for (int j = 1; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][j] == 0) {
                    cnt++;
                }
            }
            if (cnt > m / 2)    flipCol(A, j);
        }
        
        // Get result
        int score = 0;
        for (int i = 0; i < m; i++) {
            int row = 0;
            for (int j = 0; j < n; j++) {
                row = (row << 1) + A[i][j];
            }
            score += row;
        }
        
        return score;
    }
    
private:
    void flipRow(vector<vector<int>>& A, int i) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 1 - A[i][j];
        }
    }
    
    void flipCol(vector<vector<int>>& A, int j) {
        for (int i = 0; i < m; i++) {
            A[i][j] = 1 - A[i][j];
        }
    }
};
