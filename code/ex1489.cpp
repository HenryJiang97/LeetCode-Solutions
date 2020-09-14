class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);
        
        sort(edges.begin(), edges.end(), [&](vector<int>& a, vector<int>& b) -> bool {
            return a[2] < b[2];
        });
        
        // Get the original MST cost
        int MIN = prim(n, edges, -1, -1);
        
        vector<int> critical;
        vector<int> pseudo;
        for (int i = 0; i < edges.size(); i++) {
            // Force take edges[i], if larger, the edge would not be taken in any circumstance
            if (prim(n, edges, i, -1) > MIN)    continue;
            // If skip one edge makes cost larget, it's a critical edge
            if (prim(n, edges, -1, i) > MIN)    critical.push_back(edges[i][3]);
            else    pseudo.push_back(edges[i][3]);
        }
        
        return {critical, pseudo};
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
    
    bool connected(vector<int>& parent, int a, int b) {
        return find(parent, a) == find(parent, b);
    }
    
    int prim(int n, vector<vector<int>>& edges, int take, int skip) {
        int res = 0, connectedEdges = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; i++)    parent[i] = i;
        if (take >= 0) {
            res += edges[take][2];
            uni(parent, edges[take][0], edges[take][1]);
            connectedEdges++;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip || i == take)    continue;
            auto& edge = edges[i];
            int a = edge[0], b = edge[1], cost = edge[2];
            if (!connected(parent, a, b)) {
                res += cost;
                uni(parent, a, b);
                connectedEdges++;
            }
        }
        return connectedEdges == n - 1 ? res : INT_MAX;
    }
};