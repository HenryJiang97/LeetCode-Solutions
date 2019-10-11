// Dijkstra

class Solution {
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        
        int MAX = grid[0][0];
        while (!pq.empty()) {
            auto out = pq.top();    pq.pop();
            int i = out[1], j = out[2], val = out[0];
            MAX = max(MAX, val);
            
            if (out[1] == m - 1 && out[2] == n - 1)
                return MAX;
            
            // Go four directions
            for (vector<int>& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                if (visited[ni][nj])    continue;
                
                pq.push({grid[ni][nj], ni, nj});
                visited[ni][nj] = true;
            }
        }
        
        return 0;
    }
};