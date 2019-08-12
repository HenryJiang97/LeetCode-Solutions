// DFS

class Solution {
    int n;
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        
        // Mark each node with color
        bool res = true;
        vector<int> color(n);
        for (int i = 0; i < n; i++) {
            if (color[i] != 0)    continue;    // Visited
            color[i] = 1;
            res &= dfs(graph, color, i, -1);
            if (!res)    return false;
        }
        
        return res;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int start, int sign) {
        bool res = true;        
        
        vector<int>& children = graph[start];
        for (int i = 0; i < children.size(); i++) {
            if (color[children[i]] == sign)    continue;    // Visited
            if (color[children[i]] == -sign)    return false;    // Confliction inspected
            
            color[children[i]] = sign;
            res &= dfs(graph, color, children[i], -sign);
            if (!res)    return false;
        }
        
        return res;
    }
};