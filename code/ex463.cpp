class Solution {
    int m, n;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();    n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int cir = 0;
                    grid[i][j] = -1;
                    dfs(grid, i, j, cir);
                    return cir;
                }
            }
        }
        return 0;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& cir) {
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == 0) {
                cir++;
                continue;
            }
            if (grid[ni][nj] == -1)    continue;    // Visited;
            grid[ni][nj] = -1;
            dfs(grid, ni, nj, cir);
        }
    }
};