class Solution {
    vector<int> res;
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        res.resize(N);
        unordered_map<int, unordered_set<int>> graph;
        for (auto& path : paths) {
            graph[path[0] - 1].insert(path[1] - 1);
            graph[path[1] - 1].insert(path[0] - 1);
        }
        
        for (int i = 0; i < N; i++) {
            unordered_set<int> set;
            for (int next : graph[i]) {
                if (res[next] != 0)
                    set.insert(res[next]);
            }
            for (int f = 1; f <= 4; f++) {
                if (set.find(f) == set.end()) {
                    res[i] = f;
                    break;
                }
            }
        }
        
        return res;
    }
};