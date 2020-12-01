class Solution {
    int m, n;
public:
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();    n = mat[0].size();
        int MIN = INT_MAX;
        for (int flips = 0; flips < (1 << (m * n)); flips++) {
            if (valid(mat, flips)) {
                MIN = min(MIN, __builtin_popcount(flips));
            }
        }
        return MIN == INT_MAX ? -1 : MIN;
    }
    
private:
    int dir[5][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool valid(vector<vector<int>>& mat, int flips) {
        int bkp = flips;
        vector<vector<int>> after = mat;
        for (int z = 0; z < m * n; z++) {
            int f = flips & (1 << z);
            if (f == 0)    continue;
            int i = z / n, j = z % n;
            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                after[ni][nj] = 1 - after[ni][nj];
            }
        }
        
        // Verify
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (after[i][j] == 1)    return 0;
            }
        }
        return 1;
    }
};