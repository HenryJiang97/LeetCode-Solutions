class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> sol(n, string(n, '.'));
        dfs(res, sol, n, 0);
        return res;
    }
    
private:
    void dfs(vector<vector<string>>& res, vector<string>& sol, int n, int r) {
        if (r == n) {
            res.push_back(sol);
            return;
        }
        
        for (int c = 0; c < n; c++) {
            sol[r][c] = 'Q';
            if (isValid(sol, n, r, c))    dfs(res, sol, n, r + 1);
            sol[r][c] = '.';
        }
    }
    
    bool isValid(vector<string>& sol, int n, int i, int j) {
        // Check columns
        for (int r = 0; r < n; r++) {
            if (r != i && sol[r][j] == 'Q')    return false;
        }
        
        // Check diagonals
        for (int ii = i - 1, jj = j - 1; ii >= 0 && jj >= 0; ii--, jj--)
            if (sol[ii][jj] == 'Q')    return false;
        for (int ii = i - 1, jj = j + 1; ii >= 0 && jj < n; ii--, jj++)
            if (sol[ii][jj] == 'Q')    return false;
        
        return true;
    }
};