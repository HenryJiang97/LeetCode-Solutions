class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();    if (n == 0)    return {{}};
        int m = matrix[0].size();    if (m == 0)    return {{}};
        vector<vector<int>> memo(n, vector<int>(m, -1));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                memo[i][j] = dfs(matrix, memo, i, j);         
            }
        }
        
        return memo;
    }
    
private:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        if (matrix[i][j] == 0)    {memo[i][j] = 0;    return 0;}
        
        int MIN = 10000;
        // Go four directions, only down and right recursively
        if (i - 1 >= 0 && memo[i - 1][j] != -1)    MIN = min(MIN, memo[i - 1][j] + 1);
        if (j - 1 >= 0 && memo[i][j - 1] != -1)    MIN = min(MIN, memo[i][j - 1] + 1);    

        if (i + 1 < memo.size()) {
            if (memo[i + 1][j] != -1)    MIN = min(MIN, memo[i + 1][j] + 1);
            else    MIN = min(MIN, dfs(matrix, memo, i + 1, j) + 1);
        }
        if (j + 1 < memo[0].size()) {
            if (memo[i][j + 1] != -1)    MIN = min(MIN, memo[i][j + 1] + 1);
            else    MIN = min(MIN, dfs(matrix, memo, i, j + 1) + 1);
        }
        
        memo[i][j] = MIN;
        return MIN;
    }
};