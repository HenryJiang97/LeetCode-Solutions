const int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution {
    int m, n;
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();    n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != word[0])    continue;
                visited[i][j] = 1;
                if (dfs(board, word, visited, 0, i, j))    return 1;
                visited[i][j] = 0;
            }
        }
        return 0;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int s, int i, int j) {
        if (s == word.length() - 1) {
            return word[s] == board[i][j];
        }
        if (word[s] != board[i][j])    return 0;
        
        bool res = 0;
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    continue;
            visited[ni][nj] = 1;
            res |= dfs(board, word, visited, s + 1, ni, nj);
            if (res)    return 1;
            visited[ni][nj] = 0;
        }
        return res;
    }
};