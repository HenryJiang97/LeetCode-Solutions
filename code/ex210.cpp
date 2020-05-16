class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> res;
        
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n);
        for (auto& p : pre) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> que;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                que.push(i);
        
        while (!que.empty()) {
            int out = que.front();    que.pop();
            res.push_back(out);
            
            for (int nxt : graph[out]) {
                if (--indegree[nxt] == 0)    que.push(nxt);
            }
        }
        
        return res.size() == n ? res : vector<int>();
    }
};