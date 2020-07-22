class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> que;
        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            indegree[i] = graph[i].size();
            if (indegree[i] <= 1) {
                que.push(i);
            }
        }
        
        vector<int> res;
        while (!que.empty()) {
            int size = que.size();
            res.clear();
            for (int z = size; z > 0; z--) {
                int out = que.front();    que.pop();
                res.push_back(out);
                for (int nxt : graph[out]) {
                    if (indegree[nxt] <= 1)    continue;
                    if (--indegree[nxt] <= 1) {
                        que.push(nxt);   
                    }
                }
            }
        }
        
        return res;
    }
};