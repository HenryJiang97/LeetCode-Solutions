class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                if (isMagicSquare(grid, i, j))    cnt++;
            }
        }
        
        return cnt;
    }

private:
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
        vector<bool> visited(16);
        for (int ii = i; ii < i + 3; ii++)
            for (int jj = j; jj < j + 3; jj++)
                if (visited[grid[ii][jj]])    return 0;
                else    visited[grid[ii][jj]] = 1;
        for (int i = 1; i <= 9; i++)
            if (!visited[i])    return 0;
        
        int r1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int r2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        int r3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        int c1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        int c2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        int c3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
        int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int d2 = grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2];
        return r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == d1 && d1 == d2;
    }
};