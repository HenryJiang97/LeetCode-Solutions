class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination && edges.size() == 0)    return 1;
        
        // Build adjacent list
        unordered_map<int, unordered_set<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].insert(edge[1]);
        }
        
        if (graph.find(source) == graph.end())    return 0;    // No path to destination
        if (graph.find(destination) != graph.end())    return 0;    // Destination cannot have outedge
        
        bool res = 1;
        vector<int> memo(n, -1);
        vector<bool> visited(n);
        visited[source] = 1;
        return dfs(graph, destination, source, memo, visited);
    }
    
private:
    bool dfs(unordered_map<int, unordered_set<int>>& graph, int dest, int cur, vector<int>& memo, vector<bool>& visited) {
        if (cur == dest)    return 1;
        if (memo[cur] != -1)    return memo[cur] == 1 ? 1 : 0;
        
        if (graph.find(cur) == graph.end())    return 0;
        bool res = 1;
        for (int next : graph[cur]) {
            if (visited[next])    return 0;
            visited[next] = 1;
            res &= dfs(graph, dest, next, memo, visited);
            visited[next] = 0;
        }
        
        memo[cur] = res ? 1 : 0;
        return res;
    }
};