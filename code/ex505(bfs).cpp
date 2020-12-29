class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        
        int dp[101][101];
        memset(dp, 1000000, sizeof(dp));
        
        queue<vector<int>> que;
        que.push({start[0], start[1], 0});
        dp[start[0]][start[1]] = 0;
        
        int steps = 0, MIN = INT_MAX;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                vector<int> out = que.front();    que.pop();
                int i = out[0], j = out[1], d = out[2];
                if (i == destination[0] && j == destination[1]) {
                    MIN = min(MIN, d);
                    continue;
                }
                
                // Up
                int ni = i, nj = j;
                while (ni - 1 >= 0 && maze[ni - 1][nj] != 1)    ni--;
                if (d + i - ni < dp[ni][nj]) {
                    dp[ni][nj] = d + i - ni;
                    que.push({ni, nj, d + i - ni});
                }
                
                // Down
                ni = i;    nj = j;
                while (ni + 1 < m && maze[ni + 1][nj] != 1)    ni++;
                if (d + ni - i < dp[ni][nj]) {
                    dp[ni][nj] = d + ni - i;
                    que.push({ni, nj, d + ni - i});
                }
                
                // Left
                ni = i;    nj = j;
                while (nj - 1 >= 0 && maze[ni][nj - 1] != 1)    nj--;
                if (d + j - nj < dp[ni][nj]) {
                    dp[ni][nj] = d + j - nj;
                    que.push({ni, nj, d + j - nj});
                }
                
                // Right
                ni = i;    nj = j;
                while (nj + 1 < n && maze[ni][nj + 1] != 1)    nj++;
                if (d + nj - j < dp[ni][nj]) {
                    dp[ni][nj] = d + nj - j;
                    que.push({ni, nj, d + nj - j});
                }
            }
        }
        
        return MIN == INT_MAX ? -1 : MIN;
    }
};