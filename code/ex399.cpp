class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        
        vector<double> res;
        for (auto& query : queries) {
            if (graph.count(query[0]) == 0 || graph.count(query[1]) == 0) {
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            visited.insert(query[0]);
            double ret = backtracking(graph, visited, query[0], query[1]);
            res.push_back(ret == DBL_MAX ? -1.0 : ret);
        }
        
        return res;
    }
    
private:
    double backtracking(unordered_map<string, vector<pair<string, double>>>& graph, unordered_set<string>& visited, string cur, string des) {
        if (cur == des)    return 1.0;
        if (graph.count(cur) == 0)    return DBL_MAX;
        double res = DBL_MAX;
        for (pair<string, double>& nxt : graph[cur]) {
            if (visited.count(nxt.first) > 0)    continue;
            visited.insert(nxt.first);
            res = backtracking(graph, visited, nxt.first, des);
            if (res != DBL_MAX)    return res * nxt.second;
        }
        return res;
    }
};