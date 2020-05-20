class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = pid.size();
        unordered_map<int, vector<int>> graph;
        int root = -1;
        for (int i = 0; i < n; i++) {
            graph[ppid[i]].push_back(pid[i]);
            if (ppid[i] == 0)    root = pid[i];
        }
        
        vector<int> res;
        dfs(res, graph, kill);
        return res;
    }
    
private:
    void dfs(vector<int>& res, unordered_map<int, vector<int>>& graph, int cur) {
        res.push_back(cur);
        if (graph.find(cur) == graph.end())    return;
        for (int nxt : graph[cur])
            dfs(res, graph, nxt);
    }
};