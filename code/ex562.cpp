const int dir[4][2] = {{1, 0}, {0, 1}, {1, 1}, {1, -1}};

class Solution {
    int m, n;
public:
    int longestLine(vector<vector<int>>& M) {
        m = M.size();    if (m == 0)    return 0;
        n = M[0].size();    if (n == 0)    return 0;
        int MAX = 0;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(4)));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 0)    continue;
                for (int d = 0; d < 4; d++) {
                    if (visited[i][j][d])    continue;
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    int len = dfs(M, visited, i, j, d);
                    MAX = max(MAX, len);
                }
            }
        }
        return MAX;
    }
    
private:
    int dfs(vector<vector<int>>& M, vector<vector<vector<bool>>>& visited, int i, int j, int d) {
        if (i < 0 || j < 0 || i >= m || j >= n || M[i][j] == 0)    return 0;
        visited[i][j][d] = 1;
        return dfs(M, visited, i + dir[d][0], j + dir[d][1], d) + 1;
    }
};