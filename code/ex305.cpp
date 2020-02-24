const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> parent(m * n, -1);
        unordered_set<int> groups;
        vector<int> res;
        for (auto& pos : positions) {
            int i = pos[0], j = pos[1];
            if (parent[i * n + j] == -1)    parent[i * n + j] = i * n + j;
            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                if (parent[ni * n + nj] == -1)    continue;
                groups.erase(find(parent, ni * n + nj));
                uni(parent, ni * n + nj, i * n + j);
            }
            groups.insert(find(parent, i * n + j));
            res.push_back(groups.size());
        }
        return res;
    }
    
private:
    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
    
    int find(vector<int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
};