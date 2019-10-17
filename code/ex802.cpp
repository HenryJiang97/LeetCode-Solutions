class Solution {
    int n;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        n = graph.size();
        
        vector<int> res;
        vector<bool> memo(n);
        for (int i = 0; i < n; i++) {
            vector<bool> visited(n);
            if (dfs(graph, i, visited, memo))    res.push_back(i);
        }
        
        return res;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int i, vector<bool>& visited, vector<bool>& memo) {
        if (memo[i])    return true;
        bool res = true;
        for (int next : graph[i]) {
            if (visited[next])    return false;
            visited[i] = true;
            res &= dfs(graph, next, visited, memo);
            if (!res)    return false;
            visited[i] = false;
        }
        memo[i] = res;
        return res;
    }
};