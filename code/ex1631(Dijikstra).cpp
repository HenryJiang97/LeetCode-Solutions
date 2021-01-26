class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        const int dir[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        
        int MIN = INT_MAX;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(m, vector<int>(n, INT_MAX));
        pq.push({0, 0, 0});
        visited[0][0] = 1;
        while (!pq.empty()) {
            int i = pq.top()[1], j = pq.top()[2], effort = pq.top()[0];
            pq.pop();
            if (i == m - 1 && j == n - 1)    MIN = min(MIN, effort);
            else {
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                    int newEffort = max(effort, abs(heights[ni][nj] - heights[i][j]));
                    if (newEffort < visited[ni][nj]) {
                        visited[ni][nj] = newEffort;
                        pq.push({newEffort, ni, nj});
                    }
                }
            }
        }
        
        return MIN;
    }
};