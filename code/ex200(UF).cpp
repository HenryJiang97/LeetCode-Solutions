class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();    if (m == 0)    return 0;
        int n = grid[0].size();    if (n == 0)    return 0;
        
        vector<int> parent(m * n);
        for (int i = 0; i < m * n; i++)    parent[i] = i;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && i > 0 && grid[i - 1][j] == '1')
                    uni(parent, i * n + j, (i - 1) * n + j);
                if (grid[i][j] == '1' && j > 0 && grid[i][j - 1] == '1')
                    uni(parent, i * n + j, i * n + j - 1);
            }
        }
        
        unordered_set<int> set;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    set.insert(find(parent, i * n + j));
                }
            }
        }
        
        return set.size();
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