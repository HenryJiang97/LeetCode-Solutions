class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        // Find rook
        int ri = -1, rj = -1;
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] == 'R') {
                    ri = i;
                    rj = j;
                }
        
        int cnt = 0;
        // Up
        for (int i = ri - 1; i >= 0; i--) {
            if (board[i][rj] == 'p') {
                cnt++;
                break;
            } else if (board[i][rj] != '.')
                break;
        }
        
        // Down
        for (int i = ri + 1; i < 8; i++) {
            if (board[i][rj] == 'p') {
                cnt++;
                break;
            } else if (board[i][rj] != '.')
                break;
        }
        
        // Left
        for (int j = rj - 1; j >= 0; j--) {
            if (board[ri][j] == 'p') {
                cnt++;
                break;
            } else if (board[ri][j] != '.')
                break;
        }
        
        // Right
        for (int j = rj + 1; j < 8; j++) {
            if (board[ri][j] == 'p') {
                cnt++;
                break;
            } else if (board[ri][j] != '.')
                break;
        }
        
        return cnt;
    }
};