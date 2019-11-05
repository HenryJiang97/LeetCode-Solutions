// Union Find

typedef pair<int, int> ii;

class Solution {
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();    if (m == 0)    return 0;
        n = grid[0].size();    if (n == 0)    return 0;
        
        // Union adjacent
        vector<vector<ii>> parent(m, vector<ii>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                parent[i][j] = {i, j};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0')    continue;
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == '0')    continue;
                    ii root1 = find(parent, i, j), root2 = find(parent, ni, nj);
                    if (root1.first == root2.first && root1.second == root2.second)    continue;
                    uni(parent, i, j, ni, nj);
                }
            }
        }
        
        // Find clusters
        unordered_set<int> set;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0')    continue;
                ii root = find(parent, i, j);
                cout<<i<<" "<<j<<" "<<root.first<<" "<<root.second<<endl;
                set.insert(root.first * n + root.second);
            }
        }
        
        return set.size();
    }
    
private:
    ii find(vector<vector<ii>>& parent, int i, int j) {
        ii p;
        if (!(parent[i][j].first == i && parent[i][j].second == j)) {
            parent[i][j] = find(parent, parent[i][j].first, parent[i][j].second);
        }
        return parent[i][j];
    }
    
    void uni(vector<vector<ii>>& parent, int ai, int aj, int bi, int bj) {
        ii root1 = find(parent, ai, aj), root2 = find(parent, bi, bj);
        if (root1.first * root1.first + root1.second * root1.second < root2.first * root2.first + root2.second * root2.second) {
            parent[root2.first][root2.second] = {root1.first, root1.second};
        } else {
            parent[root1.first][root1.second] = {root2.first, root2.second};
        }
    }
};