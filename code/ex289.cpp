// Denote that -1 => alive to die; 2 => die to alive

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();    if (m == 0)    return;
        int n = board[0].size();    if (n == 0)    return;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                
                // Check eight directions
                if (i - 1 >= 0 && (board[i - 1][j] == 1 || board[i - 1][j] == -1))    live++;
                if (j - 1 >= 0 && (board[i][j - 1] == 1 || board[i][j - 1] == -1))    live++;
                if (i + 1 < m && (board[i + 1][j] == 1 || board[i + 1][j] == -1))    live++;
                if (j + 1 < n && (board[i][j + 1] == 1 || board[i][j + 1] == -1))    live++;
                if (i + 1 < m && j + 1 < n && (board[i + 1][j + 1] == 1 || board[i + 1][j + 1] == -1))    live++;
                if (i - 1 >= 0 && j + 1 < n && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == -1))    live++;
                if (i + 1 < m && j - 1 >= 0 && (board[i + 1][j - 1] == 1 || board[i + 1][j - 1] == -1))    live++;
                if (i - 1 >= 0 && j - 1 >= 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == -1))    live++;
               	
               	// Die
               	if (live < 2 || live > 3) {
               		if (board[i][j] == 1)    board[i][j] = -1;
               	}
               	// Alive
               	if (live == 3) {
               		if (board[i][j] == 0)    board[i][j] = 2;
               	}
               	
            }
        }

        // Replace -1 and 2
        for (int i = 0; i < m; i++) {
        	for (int j = 0; j < n; j++) {
        		if (board[i][j] == -1)    board[i][j] = 0;
        		if (board[i][j] == 2)    board[i][j] = 1;
        	}
        }
    }
};