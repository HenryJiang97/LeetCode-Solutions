class Solution {
    const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();    if (m == 0)    return 0;
        n = matrix[0].size();    if (n == 0)    return 0;
        vector<vector<int>> memo(m, vector<int>(n));
        int MAX = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                MAX = max(MAX, backtracking(matrix, memo, i, j));
            }
        }
        return MAX;
    }
    
private:
    int backtracking(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != 0)    return memo[i][j];
        
        int MAX = 1;
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || matrix[ni][nj] <= matrix[i][j])
                continue;
            MAX = max(MAX, backtracking(matrix, memo, ni, nj) + 1);
        }
        
        memo[i][j] = MAX;
        return MAX;
    }
};