class Solution {
    int m, n;
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> row = getRow(grid);
        vector<int> col = getCol(grid);
        return minDis(row) + minDis(col);
    }
    
private:
    vector<int> getRow(vector<vector<int>>& grid) {
        vector<int> row;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1)
                    row.push_back(r);
            }
        }
        return row;
    }
    
    vector<int> getCol(vector<vector<int>>& grid) {
        vector<int> col;
        for (int c = 0; c < n; c++) {
            for (int r = 0; r < m; r++) {
                if (grid[r][c] == 1)
                    col.push_back(c);
            }
        }
        return col;
    }
    
    int minDis(vector<int>& arr) {
        int dis = 0;
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            dis += (arr[hi--]) - (arr[lo++]);
        }
        return dis;
    }
};