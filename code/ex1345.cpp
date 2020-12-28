class Solution {
    
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++) {
            map[arr[i]].push_back(i);
        }
        
        vector<bool> visited(n);
        queue<int> que;
        visited[0] = 1;
        que.push(0);
        
        int steps = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                int out = que.front();    que.pop();
                if (out == n - 1)    return steps;
                if (out + 1 < n && !visited[out + 1]) {
                    visited[out + 1] = 1;
                    que.push(out + 1);
                }
                if (out - 1 >= 0 && !visited[out - 1]) {
                    visited[out - 1] = 1;
                    que.push(out - 1);
                }
                for (int nxt : map[arr[out]]) {
                    if (visited[nxt])    continue;
                    visited[nxt] = 1;
                    que.push(nxt);
                }
                map.erase(arr[out]);
            }
            steps++;
        }
        
        return steps;
    }
};