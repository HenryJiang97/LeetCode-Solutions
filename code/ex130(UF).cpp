// Union Find

const int dir[2][2] = {{-1, 0}, {0, -1}};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();    if (m == 0)    return;
        int n = board[0].size();    if (n == 0)    return;
        vector<int> parent(m * n);
        vector<bool> onBorder(m * n);
        
        // Union
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')    continue;
                parent[i * n + j] = i * n + j;
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                    onBorder[i * n + j] = 1;
                for (auto& d : dir) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n)    continue;
                    if (board[ni][nj] == 'O') {
                        uni(parent, onBorder, ni * n + nj, i * n + j);
                    }
                }
            }
        }
        
        // Find and modify
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')    continue;
                int root = find(parent, onBorder, i * n + j, false);
                if (!onBorder[root])    board[i][j] = 'X';
            }
        }
    }
    
private:
    void uni(vector<int>& parent, vector<bool>& onBorder, int a, int b) {
        bool border = onBorder[a] || onBorder[b];
        int ra = find(parent, onBorder, a, border), rb = find(parent, onBorder, b, border);
        if (ra <= rb)    parent[rb] = ra;
        else    parent[ra] = rb;
    }
    
    int find(vector<int>& parent, vector<bool>& onBorder, int a, bool border) {
        onBorder[a] = onBorder[a] || border;
        border = onBorder[a];
        if (parent[a] != a)
            parent[a] = find(parent, onBorder, parent[a], border);
        return parent[a];
    }
};