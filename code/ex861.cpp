class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int R = A.size(), C = A[0].size();
        
        // Flip rows with A[r][0] == 0
        for (int r = 0; r < R; r++) {
            if (A[r][0] == 1)    continue;
            for (int c = 0; c < C; c++) {
                A[r][c] = A[r][c] == 0 ? 1 : 0;
            }
        }
        
        // Flip cols from 1 to C - 1 which has more 0 than 1 on that col
        for (int c = 1; c < C; c++) {
            // Count zeros
            int cnt = 0;
            for (int r = 0; r < R; r++) {
                if (A[r][c] == 0)    cnt++;
            }
            if (cnt <= R / 2)    continue;
            
            // Flip
            for (int r = 0; r < R; r++)
                A[r][c] = A[r][c] == 0 ? 1 : 0;
        }
        
        // Get results
        int res = 0;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (A[r][c] == 1) {
                    res += (1 << (C - c - 1));
                }
            }
        }
        return res;
    }
};