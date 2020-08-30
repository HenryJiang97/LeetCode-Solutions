class Solution {
    int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    vector<vector<bool>> visited;
    
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();    n = grid[0].size();
        
        queue<pair<int, int>> que;
        visited = vector<vector<bool>>(m, vector<bool>(n));
        if (test(grid, 0, 0, que))    return 0;
        int cost = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                auto out = que.front();    que.pop();
                int i = out.first, j = out.second;
                
                // Try to change the arrow direction at (i, j)
                for (int d = 1; d < 5; d++) {
                    if (grid[i][j] == d)    continue;
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    continue;
                    if (test(grid, ni, nj, que))    return cost + 1;
                }
            }
            cost++;
        }
        
        return -1;
    }
    
private:
    bool test(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& que) {
        while (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j]) {
            if (i == m - 1 && j == n - 1)    return 1;
            visited[i][j] = 1;
            que.push({i, j});
            int d = grid[i][j];
            i += dir[d][0];    j += dir[d][1];
        }
        return 0;
    }
};