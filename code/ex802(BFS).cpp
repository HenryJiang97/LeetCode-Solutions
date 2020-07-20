class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<vector<int>> map(n, vector<int>());
        vector<int> outdegree(n);
        for (int i = 0; i < n; i++) {
            for (int node : graph[i]) {
                map[node].push_back(i);
            }
            outdegree[i] = graph[i].size();
        }
        
        queue<int> que;
        vector<bool> terminal(n);
        for (int i = 0; i < n; i++)
            if (outdegree[i] == 0) {
                que.push(i);
            }
                
        while (!que.empty()) {
            int out = que.front();    que.pop();
            terminal[out] = 1;
            for (int nxt : map[out]) {
                if (--outdegree[nxt] == 0)    que.push(nxt);
            }
        }
        
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (terminal[i])    res.push_back(i);
        
        return res;
    }
};