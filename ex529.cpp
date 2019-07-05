class Solution {
    int m = 0, n = 0;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        char chr[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
        
        m = board.size();    n = board[0].size();
        int cx = click[0], cy = click[1];
        // Case 1
        if (board[cx][cy] == 'M') {
            board[cx][cy] = 'X';
            return board;
        }
        
        // Case 2 and 3
        queue<pair<int, int>> q;
        q.push(make_pair(cx, cy));
        
        while (!q.empty()) {
            auto out = q.front();    q.pop();
            int x = out.first, y = out.second;
            // If current position has been modified, skip
            if (board[x][y] == 'B' || (board[x][y] >= '1' && board[x][y] <= '8'))    continue;
            
            if (ifAdjacentMine(board, x, y)) {    // Case 3
                board[x][y] = chr[mineNum(board, x, y)];
            } else {    // Add adjacent position to queue, Case 2
                board[x][y] = 'B';
                // Up
                if (x - 1 >= 0 && board[x - 1][y] == 'E')    q.push(make_pair(x - 1, y));
                // Up-Right
                if (x - 1 >= 0 && y + 1 < n && board[x - 1][y + 1] == 'E')    q.push(make_pair(x - 1, y + 1));
                // Right
                if (y + 1 < n && board[x][y + 1] == 'E')    q.push(make_pair(x, y + 1));
                // Down-Right
                if (x + 1 < m && y + 1 < n && board[x + 1][y + 1] == 'E')    q.push(make_pair(x + 1, y + 1));
                // Down
                if (x + 1 < m && board[x + 1][y] == 'E')    q.push(make_pair(x + 1, y));
                // Down-Left
                if (x + 1 < m && y - 1 >= 0 && board[x + 1][y - 1] == 'E')    q.push(make_pair(x + 1, y - 1));
                // Left
                if (y - 1 >= 0 && board[x][y - 1] == 'E')    q.push(make_pair(x, y - 1));
                // Up-Left
                if (x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 'E')    q.push(make_pair(x - 1, y - 1));
            }   
        }
        
        return board;
    }

private:
    bool ifAdjacentMine(vector<vector<char>>& board, int i, int j) {
        // Up
        if (i - 1 >= 0 && board[i - 1][j] == 'M')    return true;
        // Up-Right
        if (i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] == 'M')    return true;
        // Right
        if (j + 1 < n && board[i][j + 1] == 'M')    return true;
        // Down-Right
        if (i + 1 < m && j + 1 < n && board[i + 1][j + 1] == 'M')    return true;
        // Down
        if (i + 1 < m && board[i + 1][j] == 'M')    return true;
        // Down-Left
        if (i + 1 < m && j - 1 >= 0 && board[i + 1][j - 1] == 'M')    return true;
        // Left
        if (j - 1 >= 0 && board[i][j - 1] == 'M')    return true;
        // Up-Left
        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 'M')    return true;
        return false;
    }
    
    int mineNum(vector<vector<char>>& board, int i, int j) {
        int cnt = 0;
        // Up
        if (i - 1 >= 0 && board[i - 1][j] == 'M')    cnt++;
        // Up-Right
        if (i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] == 'M')    cnt++;
        // Right
        if (j + 1 < n && board[i][j + 1] == 'M')    cnt++;
        // Down-Right
        if (i + 1 < m && j + 1 < n && board[i + 1][j + 1] == 'M')    cnt++;
        // Down
        if (i + 1 < m && board[i + 1][j] == 'M')    cnt++;
        // Down-Left
        if (i + 1 < m && j - 1 >= 0 && board[i + 1][j - 1] == 'M')    cnt++;
        // Left
        if (j - 1 >= 0 && board[i][j - 1] == 'M')    cnt++;
        // Up-Left
        if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 'M')    cnt++;
        return cnt;
    }
};