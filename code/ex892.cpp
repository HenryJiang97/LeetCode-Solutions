const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0)    sum += 2;
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                        sum += grid[i][j];
                    } else {
                        sum += max(grid[i][j] - grid[ni][nj], 0);
                    }
                }
            }
        }
        
        return sum;
    }
};