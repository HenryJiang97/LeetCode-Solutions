// DFS

class Solution {
    private int[] visited;
    private int count = 0;
    
    // Function to mark visited friends
    private void DFS(int[][] M, int i) {
        visited[i] = 1;
        
        for (int j = 0; j < M.length; j++)
            if (M[i][j] == 1 && visited[j] == 0 && i != j)
                DFS(M, j);
    }
    
    public int findCircleNum(int[][] M) {
        visited = new int[M.length];
        
        for (int i = 0; i < M.length; i++)          
            for (int j = 0; j < M.length; j++)
                if (M[i][j] == 1 && visited[j] == 0) {
                    count++;    // Count friend circle related with ith student
                    DFS(M, j);
                }
        
        return count;
    }
}