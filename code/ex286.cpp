class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        const int m = rooms.size();    if (m == 0)    return;
        const int n = rooms[0].size();    if (n == 0)    return;
        
        queue<vector<int>> que;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    que.push({i, j});
                }
            }
        }
        
        int step = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                vector<int> out = que.front();   que.pop();
                int i = out[0], j = out[1];
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || rooms[ni][nj] != INT_MAX)
                        continue;
                    rooms[ni][nj] = step;
                    que.push({ni, nj});
                }
            }
            step++;
        }
    }
};