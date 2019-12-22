class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxRowSum = 0, maxColSum = 0, area = 0;
        for (int i = 0; i < m; i++) {
            int maxRow = 0, maxCol = 0;
            for (int j = 0; j < n; j++) {
                maxRow = max(maxRow, grid[i][j]);
                maxCol = max(maxCol, grid[j][i]);
                if (grid[i][j] != 0)    area++;
            }
            maxRowSum += maxRow;
            maxColSum += maxCol;
        }
        return area + maxRowSum + maxColSum;
    }
};