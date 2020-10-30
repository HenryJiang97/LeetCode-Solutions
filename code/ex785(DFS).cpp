// DFS

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n);
        for (int i = 0; i < n; i++) {
            if (color[i] != 0)    continue;
            color[i] = 1;
            if (!dfs(graph, color, i, color[i]))    return 0;
        }
        
        return 1;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int i, int c) {
        for (int nxt : graph[i]) {
            if (color[nxt] == c)    return 0;
            if (color[nxt] != 0)    continue;
            color[nxt] = -c;
            int ret = dfs(graph, color, nxt, -c);
            if (!ret)    return 0;
        }
        return 1;
    }
};