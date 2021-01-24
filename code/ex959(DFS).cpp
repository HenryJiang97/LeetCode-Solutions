const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
    int n;
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        
        // Build new Grid 3 times larger than the original grid
        auto Grid = vector<vector<bool>>(n * 3, vector<bool>(n * 3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    Grid[i * 3][j * 3 + 2] = 1;
                    Grid[i * 3 + 1][j * 3 + 1] = 1;
                    Grid[i * 3 + 2][j * 3] = 1;
                }
                else if (grid[i][j] == '\\') {
                    Grid[i * 3][j * 3] = 1;
                    Grid[i * 3 + 1][j * 3 + 1] = 1;
                    Grid[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        
        // Do dfs to the new grid
        int cnt = 0;
        auto visited = vector<vector<bool>>(n * 3, vector<bool>(n * 3));
        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                if (visited[i][j] || Grid[i][j])    continue;
                cnt++;
                dfs(Grid, visited, i, j);
            }
        }
        
        return cnt;
    }
    
private:
    void dfs(vector<vector<bool>>& Grid, vector<vector<bool>>& visited, int i, int j) {
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= n * 3 || nj >= n * 3 || Grid[ni][nj] || visited[ni][nj])
                continue;
            visited[ni][nj] = 1;
            dfs(Grid, visited, ni, nj);
        }
    }
};