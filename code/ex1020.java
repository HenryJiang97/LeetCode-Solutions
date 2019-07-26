class Solution {
    public int cnt = 0;
    
    public void count(int[][] A, int[][] visited, int i, int j) {
        if (i < 0 || i >= A.length || j < 0 || j >= A[0].length) {
            return;
        }
        
        if (A[i][j] == 1 && visited[i][j] == 0) {
            cnt++;
            visited[i][j] = 1;
            count(A, visited, i + 1, j);
            count(A, visited, i - 1, j);
            count(A, visited, i, j + 1);
            count(A, visited, i, j - 1);
        } else {
            return;
        }      
    }
    
    public int numEnclaves(int[][] A) {
        int visited[][] = new int[A.length][A[0].length];
        int row = A.length, col = A[0].length;
        int total = 0;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (A[i][j] == 1)    total++;
            }
        }
        
        for (int i = 0; i < row; i++) {
            if (A[i][0] == 1 && visited[i][0] == 0) { 
                cnt++;
                visited[i][0] = 1;
                count(A, visited, i + 1, 0);
                count(A, visited, i - 1, 0);
                count(A, visited, i, 1);
            }
            if (A[i][col - 1] == 1 && visited[i][col - 1] == 0) { 
                cnt++;
                visited[i][col - 1] = 1;
                count(A, visited, i + 1, col - 1);
                count(A, visited, i - 1, col - 1);
                count(A, visited, i, col - 2);
            }
        }
        
        for (int j = 0; j < col; j++) {
            if (A[0][j] == 1 && visited[0][j] == 0) {
                cnt++;
                visited[0][j] = 1;
                count(A, visited, 0, j + 1);
                count(A, visited, 0, j - 1);
                count(A, visited, 1, j);
            }
            if (A[row - 1][j] == 1 && visited[row - 1][j] == 0) { 
                cnt++;
                visited[row - 1][j] = 1;
                count(A, visited, row - 1, j + 1);
                count(A, visited, row - 1, j - 1);
                count(A, visited, row - 2, j);
            }
        }
        
        // System.out.println(cnt);
        
        return total - cnt;
    }
}