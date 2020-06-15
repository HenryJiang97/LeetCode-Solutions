class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();    if (m == 0)    return 0;
        int n = matrix[0].size();    if (n == 0)    return 0;
        
        // Get max consecutive 1s for each row
        vector<vector<int>> consec(m, vector<int>());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                consec[i].push_back(j == 0 ? matrix[i][j] - '0' : matrix[i][j] == '0' ? 0 : consec[i].back() + 1);
            }
        }
        
        int MAX = 0;
        for (int c = 0; c < n; c++) {
            for (int r1 = 0; r1 < m; r1++) {
                if (consec[r1][c] == 0)    continue;
                int MIN = INT_MAX;
                for (int r2 = r1; r2 < m; r2++) {
                    if (consec[r2][c] == 0)    break;
                    MIN = min(MIN, consec[r2][c]);
                    MAX = max(MAX, (r2 - r1 + 1) * MIN);
                }
            }
        }
        
        return MAX;
    }
};