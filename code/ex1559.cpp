class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<int> parent(m * n);
        for (int i = 0; i < m * n; i++)    parent[i] = i;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0 && j > 0) {
                    if (grid[i][j] == grid[i - 1][j] && grid[i][j] == grid[i][j - 1] && find(parent, (i - 1) * n + j) == find(parent, i * n + j - 1))
                        return 1;
                }
                if (i > 0 && grid[i][j] == grid[i - 1][j])    uni(parent, i * n + j, (i - 1) * n + j);
                if (j > 0 && grid[i][j] == grid[i][j - 1])    uni(parent, i * n + j, i * n + j - 1);
            }
        }
        
        return 0;
    }
    
private:
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