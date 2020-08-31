class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();    if (n <= 1)    return 0;
        
        // Get all idxs for a certain value in the array
        unordered_map<int, unordered_set<int>> idxs;
        for (int i = 0; i < n; i++) {
            idxs[arr[i]].insert(i);
        }
        
        // BFS
        queue<int> que;
        que.push(0);
        vector<bool> visited(n);
        visited[0] = 1;
        int step = 0;
        
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                int out = que.front();    que.pop();
                if (out == n - 1)    return step;
                if (out + 1 < n && !visited[out + 1])    que.push(out + 1);
                if (out - 1 >= 0 && !visited[out - 1])    que.push(out - 1);
                
                vector<int> nexts;
                for (int idx : idxs[arr[out]]) {
                    if (visited[idx])    continue;
                    visited[idx] = 1;
                    nexts.push_back(idx);
                    que.push(idx);
                }
                
                for (int next : nexts)    // Remove idxs used
                    idxs[arr[out]].erase(next);
            }
            step++;
        }
        
        return -1;
    }
};