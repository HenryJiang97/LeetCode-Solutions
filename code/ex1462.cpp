class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Get graph
        vector<vector<int>> graph(n, vector<int>());
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        
        vector<vector<int>> memo(n, vector<int>(n, -1));
        vector<bool> res, visited(n);
        for (auto& q : queries) {
            int cur = q[1], target = q[0];
            visited[cur] = 1;
            res.push_back(backtracking(graph, memo, visited, cur, target));
            visited[cur] = 0;
        }
        
        return res;
    }
    
private:
    bool backtracking(vector<vector<int>>& graph, vector<vector<int>>& memo, vector<bool>& visited, int cur, int target) {
        if (cur == target)    return 1;
        if (memo[cur][target] != -1)    return memo[cur][target];
        
        bool res = 0;
        for (int nxt : graph[cur]) {
            if (visited[nxt])    continue;
            visited[nxt] = 1;
            res |= backtracking(graph, memo, visited, nxt, target);
            visited[nxt] = 0;
            if (res)    break;
        }
        
        memo[cur][target] = res;
        return res;
    }
};