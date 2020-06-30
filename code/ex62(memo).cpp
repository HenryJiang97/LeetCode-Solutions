class Solution {
    int m, n;
    vector<vector<int>> dir = {{1, 0}, {0, 1}};
public:
    int uniquePaths(int m, int n) {
        this->m = m;    this->n = n;
        vector<vector<int>> memo(m, vector<int>(n, 0));
        return dfs(memo, 0, 0);
    }
    
private:
    int dfs(vector<vector<int>>& memo, int i, int j) {
        if (i == m - 1 && j == n - 1)    return 1;        
        
        if (memo[i][j] != 0)    return memo[i][j];
        
        int cnt = 0;
        for (int d = 0; d < 2; d++) {
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if (ni >= m || nj >= n)    continue;
            cnt += dfs(memo, ni, nj);
        }
        
        memo[i][j] = cnt;
        return cnt;
    }
};