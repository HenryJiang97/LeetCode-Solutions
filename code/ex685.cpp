// 1. One node has two parents
// 2. Cycle exists in the graph

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Get parent for each node
        vector<int> parent(n + 1);
        vector<int> cand1, cand2;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] == 0) {
                parent[v] = u;
            } else {
                cand1 = {parent[v], v};
                cand2 = edge;
            }
        }
        
        // Test if there's cycle in the graph without cand2
        parent = vector<int>(n + 1);
        for (int i = 1; i <= n; i++)    parent[i] = i;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (!cand2.empty() && u == cand2[0] && v == cand2[1])    continue;
            
            int ru = find(parent, u);
            if (ru == v) {    // Found a cycle
                if (cand1.empty())    return edge;    // No candidate, but with cycle
                else    return cand1;
            }
            parent[v] = ru;
        }
        
        return cand2;
    }
    
private:
    int find(vector<int>& parent, int a) {
        if (parent[a] != a)
            parent[a] = find(parent, parent[a]);
        return parent[a];
    }
};