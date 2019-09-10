class Solution {
    public boolean validTicTacToe(String[] board) {
        char[][] map = new char[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                map[i][j] = board[i].charAt(j);
            }
        }
        
        int nx = 0, no = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (map[i][j] == 'X')    nx++;
                else if (map[i][j] == 'O')    no++;
            }
        }
        
        if (nx != no + 1 && nx != no)    return false;
        
        // Judge if anyone wins
        boolean XWin = ifWin(map, 'X'), OWin = ifWin(map, 'O');
        
        if (XWin && nx != no + 1)    return false;
        if (OWin && nx != no)    return false;
        
        return true;
    }
    
    private boolean ifWin(char[][] map, char c) {
        for (int i = 0; i < 3; i++) {
            if (map[i][0] == c && map[i][1] == c && map[i][2] == c)    return true;
        }
        for (int j = 0; j < 3; j++) {
            if (map[0][j] == c && map[1][j] == c && map[2][j] == c)    return true;
        }
        if (map[0][0] == c && map[1][1] == c && map[2][2] == c)    return true;
        if (map[0][2] == c && map[1][1] == c && map[2][0] == c)    return true;
        return false;
    }
}