// DFS

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> group(n);
        for (int i = 0; i < n; i++) {
            if (group[i] != 0)    continue;    // Visited
            if (!dfs(graph, group, i, 1))    return 0;
        }
        
        return 1;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& group, int cur, int color) {
        for (int nxt : graph[cur]) {
            if (group[nxt] != 0) {    // Visited
                if (group[nxt] != color)    return 0;
            } else {    // Not visited
                group[nxt] = color;
                if (!dfs(graph, group, nxt, -color))    return 0;
            }
        }
        return 1;
    }
};