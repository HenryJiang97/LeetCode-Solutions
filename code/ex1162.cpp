const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        // BFS
        queue<vector<int>> que;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    que.push({i, j});
        if (que.size() == m * n)    return -1;
        
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                int i = que.front()[0], j = que.front()[1];
                que.pop();
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == 1)    continue;
                    grid[ni][nj] = 1;
                    que.push({ni, nj});
                }
            }
            if (que.size() == 0)    return step;
            step++;
        }
        
        return -1;
    }
};