class Solution {
    int n;
    unordered_set<int> keys;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();    if (n <= 1)    return 1;
        
        vector<bool> visited(n);
        visited[0] = 1;
        keys.insert(0);
        return dfs(rooms, visited, 0);
    }
    
private:
    bool dfs(vector<vector<int>>& rooms, vector<bool>& visited, int cur) {
        for (int key : rooms[cur]) {
            keys.insert(key);
            if (keys.size() == n)    return 1;
            if (visited[key])    continue;
            visited[key] = 1;
            bool ret = dfs(rooms, visited, key);
            if (ret)    return 1;
        }
        return 0;
    }
};