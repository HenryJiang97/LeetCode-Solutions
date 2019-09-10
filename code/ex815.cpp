class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)    return 0;
        int n = routes.size();
        
        // Build map
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                map[stop].push_back(i);
            }
        }
        
        // BFS
        queue<int> que;
        que.push(S);
        int cnt = 0;
        unordered_set<int> visitedBus;
        unordered_set<int> visitedStop;    visitedStop.insert(S);
        
        while (!que.empty()) {
            for (int z = que.size(); z > 0; --z) {
                int out = que.front();    que.pop();
                
                for (auto bus : map[out]) {
                    if (visitedBus.find(bus) != visitedBus.end())    continue;
                    visitedBus.insert(bus);
                    
                    for (int stop : routes[bus]) {
                        if (visitedStop.find(stop) != visitedStop.end())    continue;
                        if (stop == T)    return cnt + 1;
                        que.push(stop);
                        visitedStop.insert(stop);
                    }
                }
            }
            
            cnt++;
        }
        
        return -1;
    }
};