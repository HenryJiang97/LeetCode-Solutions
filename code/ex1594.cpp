class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7, m = grid.size(), n = grid[0].size();
        int dir[2][2] = {{-1, 0}, {0, -1}};
        
        vector<vector<long>> pos(m, vector<long>(n, INT_MIN));
        vector<vector<long>> neg(m, vector<long>(n, INT_MAX));
        if (grid[m - 1][n - 1] > 0) {
            pos[m - 1][n - 1] = grid[m - 1][n - 1];
        } else if (grid[m - 1][n - 1] < 0) {
            neg[m - 1][n - 1] = grid[m - 1][n - 1];
        } else {
            pos[m - 1][n - 1] = neg[m - 1][n - 1] = 0;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0)    continue;
                    if (grid[ni][nj] > 0) {
                        pos[ni][nj] = max(pos[ni][nj], pos[i][j] * grid[ni][nj]);
                        neg[ni][nj] = min(neg[ni][nj], neg[i][j] * grid[ni][nj]);
                    } else if (grid[ni][nj] < 0) {
                        pos[ni][nj] = max(pos[ni][nj], neg[i][j] * grid[ni][nj]);
                        neg[ni][nj] = min(neg[ni][nj], pos[i][j] * grid[ni][nj]);
                    } else {
                        pos[ni][nj] = neg[ni][nj] = 0;
                    }
                }
            }
        }
        
        return pos[0][0] >= 0 ? (int)(pos[0][0] % mod) : -1;
    }
};