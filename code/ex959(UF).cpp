class Solution {
    int m, n;
public:
    int regionsBySlashes(vector<string>& grid) {
        m = grid.size();    n = grid[0].size();
        vector<int> parent(m * n * 5);
        iota(parent.begin(), parent.end(), 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == ' ') {
                    uni(parent, code(i, j, 1), code(i, j, 2));
                    uni(parent, code(i, j, 1), code(i, j, 3));
                    uni(parent, code(i, j, 1), code(i, j, 4));
                } else if (grid[i][j] == '/') {
                    uni(parent, code(i, j, 1), code(i, j, 4));
                    uni(parent, code(i, j, 2), code(i, j, 3));
                } else {
                    uni(parent, code(i, j, 1), code(i, j, 2));
                    uni(parent, code(i, j, 3), code(i, j, 4));
                }
                
                if (j > 0) {
                    uni(parent, code(i, j - 1, 2), code(i, j, 4));
                }
                if (i > 0) {
                    uni(parent, code(i - 1, j, 3), code(i, j, 1));
                }
            }
        }
        
        unordered_set<int> regions;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int p = 1; p <= 4; p++) {
                    regions.insert(find(parent, code(i, j, p)));
                }
            }
        }
        
        return regions.size();
    }
    
private:
    int code(int i, int j, int piece) {
        return (i * n + j) + m * n * piece;
    }
    
    int find(vector<int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }

    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra < rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
};