class Solution {
    int m, n;
public:
    int cutOffTree(vector<vector<int>>& forest) {
        m = forest.size();    n = forest[0].size();
        if (forest[0][0] == 0)    return -1;
        
        vector<vector<int>> dict;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    dict.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(dict.begin(), dict.end());
        
        int steps = 0;
        int i = 0, j = 0;
        for (auto& d : dict) {
            int ni = d[1], nj = d[2];
            int ret = getSteps(forest, i, j, ni, nj);
            if (ret == -1)    return -1;
            steps += ret;
            i = ni;    j = nj;
        }
        
        return steps;
    }
    
private:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int getSteps(vector<vector<int>>& forest, int fi, int fj, int di, int dj) {
        // BFS
        vector<vector<bool>> visited(m, vector<bool>(n));
        queue<pair<int, int>> que;
        que.push({fi, fj});
        visited[fi][fj] = 1;
        int steps = 0;
        
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                pair<int, int> out = que.front();    que.pop();
                int i = out.first, j = out.second;
                if (i == di && j == dj)    return steps;
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n ||
                        visited[ni][nj] || forest[ni][nj] == 0)
                        continue;
                    visited[ni][nj] = 1;
                    que.push({ni, nj});
                }
            }
            steps++;
        }
        
        return -1;
    }
};