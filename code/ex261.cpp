// Cannot have circle and cannot be a forest
// DFS

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (auto edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        
        vector<bool> visited(n);
        bool res = dfs(graph, visited, 0, 0);
        visited[0] = true;
        if (!res)    return false;
        for (bool v : visited)    if (!v)    return false;
        return res;
    }
    
private:
    bool dfs(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int i, int parent) {
        bool ret = true;
        for (auto next : graph[i]) {
            if (next == parent)    continue;
            if (visited[next])    return false;
            visited[next] = true;
            ret &= dfs(graph, visited, next, i);
            if (!ret)    return false;
        }
        return ret;
    }
};