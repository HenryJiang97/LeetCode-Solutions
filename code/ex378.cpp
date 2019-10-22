// Heap

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({matrix[0][0], 0, 0});
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[0][0] = 1;
        
        while (!pq.empty()) {
            auto out = pq.top();    pq.pop();
            int i = out[1], j = out[2];
            if (--k == 0)    return out[0];
                        
            // Add next elements to the pq
            if (j + 1 < n && !visited[i][j + 1]) {
                visited[i][j + 1] = 1;
                pq.push({matrix[i][j + 1], i, j + 1});
            }
            
            if (i + 1 < m && !visited[i + 1][j]) {
                visited[i + 1][j] = 1;
                pq.push({matrix[i + 1][j], i + 1, j});
            }
        }
        
        return -1;
    }
};