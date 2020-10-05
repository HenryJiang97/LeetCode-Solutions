class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> graph(N, vector<int>());
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> res(N);
        vector<int> cnt(N, 1);    // Count of children nodes
        dfs1(graph, res, cnt, 0, -1);
        dfs2(graph, res, cnt, 0, -1);
        
        return res;
    }
    
private:
    void dfs1(vector<vector<int>>& graph, vector<int>& res, vector<int>& cnt, int cur, int parent) {
        for (int nxt : graph[cur]) {
            if (nxt == parent)    continue;
            dfs1(graph, res, cnt, nxt, cur);
            cnt[cur] += cnt[nxt];
            res[cur] += res[nxt] + cnt[nxt];
        }
    }
    
    void dfs2(vector<vector<int>>& graph, vector<int>& res, vector<int>& cnt, int cur, int parent) {
        for (int nxt : graph[cur]) {
            if (nxt == parent)    continue;
            res[nxt] = res[cur] - cnt[nxt] + cnt.size() - cnt[nxt];
            dfs2(graph, res, cnt, nxt, cur);
        }
    }
};