// Union Find
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // Get the total nodes in the graph
        unordered_set<int> set;
        for (auto& edge: edges) {
            set.insert(edge[0]);
            set.insert(edge[1]);
        }
        int n = set.size();
        
        // Build parent array
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)    parent[i] = i;

        for (auto& edge: edges) {
            int u = edge[0], v = edge[1];
            if (find(parent, u) == find(parent, v))    return edge;
            uni(parent, u, v);
        }

        return {};
    }

private:
    int find(vector<int>& parent, int p) {
        if (parent[p] != p)
            parent[p] = find(parent, parent[p]);
        return parent[p];
    }

    void uni(vector<int>& parent, int a, int b) {
        int ra = find(parent, a), rb = find(parent, b);
        if (ra <= rb)
            parent[rb] = ra;
        else
            parent[ra] = rb;
    }
};