class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> next(n, vector<int>());
        
        // Get indegree
        vector<int> indegree(n);
        for (auto& pre : prerequisites) {
            next[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        
        int cnt = 0;
        queue<int> que;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                que.push(i);
                cnt++;   
            }
        }
        
        while (!que.empty()) {
            int out = que.front();    que.pop();
            for (int nxt : next[out]) {
                if (--indegree[nxt] == 0) {
                    que.push(nxt);
                    cnt++;
                }
            }
        }
        
        return cnt == n;
    }
};