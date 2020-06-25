class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path{0};
        dfs(graph, res, 0, graph.size() - 1, path);
        return res;
    }
    
private:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, int cur, int target, vector<int>& path) {
        if (cur == target) {
            res.push_back(path);
            return;
        }
        
        for (int nxt : graph[cur]) {
            path.push_back(nxt);
            dfs(graph, res, nxt, target, path);
            path.pop_back();
        }
    }
};