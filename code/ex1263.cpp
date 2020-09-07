class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int m = grid.size(), n = grid[0].size();
        int sx, sy, bx, by, tx, ty;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    sx = i;    sy = j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'B') {
                    bx = i;    by = j;
                    grid[i][j] = '.';
                } else if (grid[i][j] == 'T') {
                    tx = i;    ty = j;
                    grid[i][j] = '.';
                }
            }
        }
        
        int level[21][21][21][21];
        memset(level, -1, sizeof(level));
        deque<vector<int>> dque;
        dque.push_back({sx, sy, bx, by});
        level[sx][sy][bx][by] = 0;
        
        while (!dque.empty()) {
            auto out = dque.front();    dque.pop_front();
            int i = out[0], j = out[1], bi = out[2], bj = out[3];
            if (bi == tx && bj == ty)    return level[i][j][bi][bj];
            
            for (auto& d : dir) {    // Move player
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                if (grid[ni][nj] != '.' || level[ni][nj][bi][bj] != -1 || (ni == bi && nj == bj))
                    continue;
                dque.push_front({ni, nj, bi, bj});
                level[ni][nj][bi][bj] = level[i][j][bi][bj];
            }
            
            if (abs(i - bi) + abs(j - bj) == 1) {    // Move box
                for (auto& d : dir) {
                    if (i + d[0] == bi && j + d[1] == bj) {
                        int ni = bi, nj = bj;
                        int nbi = bi + d[0], nbj = bj + d[1];
                        if (nbi < 0 || nbj < 0 || nbi >= m || nbj >= n)    continue;
                        if (grid[nbi][nbj] != '.' || level[ni][nj][nbi][nbj] != -1)    continue;
                        dque.push_back({ni, nj, nbi, nbj});
                        level[ni][nj][nbi][nbj] = level[i][j][bi][bj] + 1;
                    }
                }
                
            }
        }
        
        return -1;
    }
};