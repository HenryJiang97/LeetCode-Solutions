// DFS + memo

class Solution {
    public boolean divisorGame(int N) {
        boolean[] memo = new boolean[N + 1];
        return dfs(N, memo);
    }
    
    private boolean dfs(int N, boolean[] memo) {    // Player: 1 => Alice; -1 => Bob
        if (N <= 1)    return false;
        if (memo[N])    return true;
        boolean res = false;
        for (int x = 1; x < N; x++) {
            if (N % x != 0)    continue;
            if (!dfs(N - x, memo)) {res = true;    break;}
        }
        memo[N] = res;
        return res;
    }
}