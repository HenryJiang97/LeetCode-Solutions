class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int dir[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<vector<int>> que;
        if (grid[0][0] == 1)    return -1;
        que.push({0, 0, 1});
        dp[0][0] = 1;
        
        int MIN = INT_MAX;
        while (!que.empty()) {
            vector<int> out = que.front();    que.pop();
            int i = out[0], j = out[1], dis = out[2];
            if (i == m - 1 && j == n - 1) {
                MIN = min(MIN, dis);
                continue;
            }
            
            for (auto& d : dir) {
                int ni = i + d[0], nj = j + d[1];
                if (ni < 0 || nj < 0 || ni >= m || nj >= n || grid[ni][nj] == 1)    continue;
                if (dis + 1 < dp[ni][nj]) {
                    que.push({ni, nj, dis + 1});
                    dp[ni][nj] = dis + 1;
                }
            }
        }
        
        return MIN == INT_MAX ? -1 : MIN;
    }
};