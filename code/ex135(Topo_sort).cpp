class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        // Build graph
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            if (i - 1 >= 0 && ratings[i - 1] > ratings[i])
                graph[i].push_back(i - 1);
            if (i + 1 < n && ratings[i] < ratings[i + 1])
                graph[i].push_back(i + 1);
        }
        
        // Topological sort
        vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            for (int nxt : graph[i]) {
                indegree[nxt]++;
            }
        }
        
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        
        int res = 0, candies = 1;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int out = que.front();    que.pop();
                res += candies;
                for (int nxt : graph[out]) {
                    if (--indegree[nxt] == 0) {
                        que.push(nxt);
                    }
                }
            }
            candies++;
        }
        
        return res;
    }
};