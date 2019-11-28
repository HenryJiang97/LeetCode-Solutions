// DFS

class Solution {
    int res = 0;
    int m, n;
    int ti, tj;
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();    n = grid[0].size();
        int remain = 0, si = 0, sj = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    si = i;    sj = j;
                } else if (grid[i][j] != -1) {
                    if (grid[i][j] == 2) {
                        ti = i;    tj = j;
                    }
                    remain++;
                }
            }
        }
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[si][sj] = 1;
        dfs(grid, si, sj, remain, visited);
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int remain, vector<vector<bool>>& visited) {
        if (remain == 0) {
            if (i == ti && j == tj)    res++;
            return;
        }
        
        if (i == ti && j == tj)    return;
        
        for (auto d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj] || grid[ni][nj] == -1)    continue;
            visited[ni][nj] = 1;
            dfs(grid, ni, nj, remain - 1, visited);
            visited[ni][nj] = 0;
        }
        
    }
};