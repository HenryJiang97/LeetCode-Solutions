typedef pair<int, int> ii;

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        // Build adjacent list
        unordered_map<int, unordered_map<int, int>> m;
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            m[u][v] = w;
            m[v][u] = w;
        }
        
        // Dijkstra
        int res = 0;
        vector<bool> visited(N);
        priority_queue<ii> pq;    // {Remaining step, node id}
        pq.push({M, 0});
        while (!pq.empty()) {
            auto out = pq.top();    pq.pop();
            int remain = out.first, cur = out.second;
            if (visited[cur])    continue;
            visited[cur] = true;
            res++;
            
            // Find next node;
            for (auto& next : m[cur]) {
                if (remain > next.second && !visited[next.first]) {    // Can reach next point
                    pq.push({remain - (next.second + 1), next.first});
                    m[next.first][cur] = 0;
                } else {    // Cannot reach next point
                    m[next.first][cur] -= remain;
                }
                res += min(remain, next.second);
            }
        }
        
        return res;
    }
};