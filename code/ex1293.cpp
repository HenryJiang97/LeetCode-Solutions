class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
        const int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(K + 1)));
        visited[0][0][K] = 1;
        queue<vector<int>> que;
        que.push({0, 0, K});
        
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                vector<int> out = que.front();    que.pop();
                int i = out[0], j = out[1], k = out[2];
                if (i == m - 1 && j == n - 1)    return step;
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                    int nk = grid[ni][nj] ? k - 1 : k;
                    if (nk < 0 || visited[ni][nj][nk])    continue;
                    visited[ni][nj][nk] = 1;
                    que.push({ni, nj, nk});
                }
            }
            step++;
        }
        
        return -1;
    }
};