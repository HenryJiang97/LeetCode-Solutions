class Solution {
    int m, n;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();    n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 1;
                if (dfs(board, visited, word, i, j, 0))
                    return 1;
                visited[i][j] = 0;
            }
        }
        return 0;
    }
    
private:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int j, int s) {
        if (s == word.length() - 1 && word[s] == board[i][j])    return 1;
        if (word[s] != board[i][j])    return 0;
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    continue;
            visited[ni][nj] = 1;
            if (dfs(board, visited, word, ni, nj, s + 1))    return 1;
            visited[ni][nj] = 0;
        }
        return 0;
    }
};