class Solution {
    int res = 0;
public:
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)    continue;
                if ((int)sqrt(A[i] + A[j]) * (int)sqrt(A[i] + A[j]) == A[i] + A[j]) {
                    graph[i].push_back(j);
                }
            }
        }
        
        // DFS
        vector<bool> visited(n);
        for (int i = 0; i < n; i++) {
            if (i > 0 && A[i] == A[i - 1])    continue;
            visited[i] = 1;
            dfs(A, graph, visited, i, 1);
            visited[i] = 0;
        }
        
        return res;
    }
    
    void dfs(vector<int>& A, vector<vector<int>>& graph, vector<bool>& visited, int i, int len) {
        if (len == A.size()) {
            res++;
            return;
        }
        
        int prev = -1;
        for (int nxt : graph[i]) {
            if (visited[nxt] || A[nxt] == prev)    continue;
            prev = A[nxt];
            visited[nxt] = 1;
            dfs(A, graph, visited, nxt, len + 1);
            visited[nxt] = 0;
        }
    }
};