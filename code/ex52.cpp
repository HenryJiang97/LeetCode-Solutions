class Solution {
    int cnt = 0;
public:
    int totalNQueens(int n) {
        vector<string> sol(n, string(n, '.'));
        dfs(sol, n, 0);
        return cnt;
    }
    
private:
    void dfs(vector<string>& sol, int n, int r) {
        if (r == n) {
            cnt++;
            return;
        }
        
        for (int c = 0; c < n; c++) {
            sol[r][c] = 'Q';
            if (isValid(sol, n, r, c))    dfs(sol, n, r + 1);
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