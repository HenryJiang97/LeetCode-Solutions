class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int m, int n, int r0, int c0) {
        const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> res;
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<vector<int>> que;
        que.push({r0, c0});
        visited[r0][c0] = 1;
        while (!que.empty()) {
            vector<int> out = que.front();    que.pop();
            int i = out[0], j = out[1];
            res.push_back({i, j});
            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    continue;
                visited[ni][nj] = 1;
                que.push({ni, nj});
            }
        }
        return res;
    }
};