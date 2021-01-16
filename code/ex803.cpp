class Solution {
    int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    vector<vector<int>> grid;
    vector<int> parent, size;
    int m, n;
    
public:
    vector<int> hitBricks(vector<vector<int>>& g, vector<vector<int>>& hits) {
        this->grid = g;
        m = grid.size();    n = grid[0].size();
        for (auto& hit : hits) {
            if (grid[hit[0]][hit[1]] == 1)
                grid[hit[0]][hit[1]] = 2;
        }
        
        parent = vector<int>(m * n + 1);
        size = vector<int>(m * n + 1, 1);
        size[0] = 0;
        iota(parent.begin(), parent.end(), 0);
        
        // Union up bricks left after final hit
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    unionUp(i, j);
            }
        }
        
        // Reversely make up hitten bricks
        vector<int> res(hits.size());
        int bricks = size[0];
        
        for (int z = hits.size() - 1; z >= 0; z--) {
            int i = hits[z][0], j = hits[z][1];
            if (grid[i][j] == 2) {
                grid[i][j] = 1;
                unionUp(i, j);
                int newBricks = size[0];
                res[z] = max(0, newBricks - bricks - 1);
                bricks = newBricks;
            }
        }
        
        return res;
    }
    
private:
    // Union Find
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }
    
    void uni(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra < rb) {
            parent[rb] = ra;
            size[ra] += size[rb];
        } else if (ra > rb) {
            parent[ra] = rb;
            size[rb] += size[ra];
        }
    }
    
    // Union Up
    void unionUp(int i, int j) {
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] != 1)    continue;
            uni(ni * n + nj + 1, i * n + j + 1);
        }
        if (i == 0)    uni(0, i * n + j + 1);
    }
};