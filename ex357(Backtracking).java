// Backtracking

class Solution {
    public int cnt = 0;
    
    public void bt(int n, int[] visited) {
        if (n == 0) {
            cnt++;    return;
        }
        
        for (int i = 0; i < 10; i++) {
            if (visited[i] == 1)    continue;          
            visited[i] = 1;
            bt(n - 1, visited);
            visited[i] = 0;
        }
    }
    
    public void backtracking(int n) {
        // 1 => visited; 0 => unvisited
        int[] visited = new int[10];
        
        for (int i = 1; i < 10; i++) {
            visited[i] = 1;
            bt(n - 1, visited);
            visited[i] = 0;
        }
    }
    
    public int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        
        for (int i = 0; i <= n; i++) {
            backtracking(i);
            res += cnt;
            cnt = 0;
        }     
        
        return res;
    }
}