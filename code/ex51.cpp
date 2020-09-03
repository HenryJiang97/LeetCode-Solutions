class Solution {
    int n;
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<vector<string>> res;
        vector<string> cur;
        dfs(res, cur, 0);
        return res;
    }
    
private:
    void dfs(vector<vector<string>>& res, vector<string>& cur, int s) {
        if (s >= n) {
            res.push_back(cur);
            return;
        }
        
        string row = string(n, '.');
        for (int i = 0; i < n; i++) {
            if (!valid(cur, i))    continue;
            row[i] = 'Q';
            cur.push_back(row);
            dfs(res, cur, s + 1);
            cur.pop_back();
            row[i] = '.';
        }
    }
    
    bool valid(vector<string>& grid, int j) {
        int m = grid.size();
        for (int ii = m - 1, jj = j + 1; ii >= 0 && jj < n; ii--, jj++)
            if (grid[ii][jj] == 'Q')    return 0;
        for (int ii = m - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--)
            if (grid[ii][jj] == 'Q')    return 0;
        for (int ii = m - 1; ii >= 0; ii--)
            if (grid[ii][j] == 'Q')    return 0;
        return 1;
    }
};