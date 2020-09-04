class Solution {
    int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int m, n;
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();    if (m == 0)    return {};
        n = matrix[0].size();    if (n == 0)    return {};
        
        vector<int> res;
        vector<vector<bool>> visited(m, vector<bool>(n));
        int i = 0, j = -1, d = 0;
        while (1) {
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    changeDir(d);
            else {
                res.push_back(matrix[ni][nj]);
                visited[ni][nj] = 1;
                i = ni;    j = nj;
            }
            if (end(visited, i, j))    break;
        }
        
        return res;
    }
    
private:
    void changeDir(int& d) {
        if (d == 3)    d = 0;
        else    d++;
    }
    
    bool end(vector<vector<bool>>& visited, int i, int j) {
        bool ifEnd = 1;
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
            if (!visited[ni][nj])    return 0;
        }
        return ifEnd;
    }
};