class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();    if (m == 0)    return 0;
        int n = matrix[0].size();
        
        // Get the maximum length of continuous 1s before c in each row
        auto prefix = vector<vector<int>>(m, vector<int>(n));
        for (int r = 0; r < m; r++) {
            prefix[r][0] = matrix[r][0] - '0';
            for (int c = 1; c < n; c++) {
                prefix[r][c] = matrix[r][c] == '1' ? prefix[r][c - 1] + 1 : 0;
            }
        }
        
        // Get the maximum area of rectangle
        int MAX = 0;
        for (int c = 0; c < n; c++) {
            for (int r1 = 0; r1 < m; r1++) {
                int MIN_LEN = INT_MAX;
                for (int r2 = r1; r2 >= 0; --r2) {
                    if (prefix[r2][c] == 0)    break;
                    MIN_LEN = min(MIN_LEN, prefix[r2][c]);
                    MAX = max(MAX, MIN_LEN * (r1 - r2 + 1));
                }
            }
        }
        
        return MAX;
    }
};