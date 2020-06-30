// Eulerian path (欧拉环路)
//         -> D -> E
// A -> B <-> F   

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        
        unordered_map<string, queue<string>> map;
        for (auto& ticket : tickets) {
            map[ticket[0]].push(ticket[1]);
        }
        
        vector<string> path;
        dfs(map, path, "JFK");
        reverse(path.begin(), path.end());
        return path;
    }
    
private:
    void dfs(unordered_map<string, queue<string>>& map, vector<string>& path, string cur) {
        while (!map[cur].empty()) {
            string nxt = map[cur].front();
            map[cur].pop();
            dfs(map, path, nxt);
        }
        path.push_back(cur);
    }
};