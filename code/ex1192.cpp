class Solution {
    vector<vector<int>> res;
    vector<int> dis, low;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        
        dis = vector<int>(n, -1);
        low = vector<int>(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (dis[i] != -1)    continue;
            dfs(graph, i, -1);
        }
        
        return res;
    }
    
private:
    int time = 0;
    
    void dfs(vector<vector<int>>& graph, int cur, int parent) {
        dis[cur] = time;    low[cur] = time;    time++;
        
        for (int nxt : graph[cur]) {
            if (nxt == parent)    continue;
            
            if (dis[nxt] == -1) {    // Nxt not visited
                dfs(graph, nxt, cur);
                low[cur] = min(low[cur], low[nxt]);
                if (low[nxt] > dis[cur]) {
                    res.push_back({cur, nxt});
                }
            } else {
                low[cur] = min(low[cur], dis[nxt]);
            }
        }
    }
};