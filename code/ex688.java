// Standard DFS with memo

import java.util.*;

class Solution {
    public double knightProbability(int N, int K, int r, int c) {
        double[][][] memo = new double[K][N][N];
        for (int k = 0; k < K; k++)
            for (int i = 0; i < N; i++)
                Arrays.fill(memo[k][i], -1);
        return dfs(N, K, 0, r, c, memo);
    }
    
    private double dfs(int N, int K, int k, int x, int y, double[][][] memo) {
        if (x < 0 || x >= N || y < 0 || y >= N)    return 0.0;
        if (k == K)    return 1.0;
        
        if (memo[k][x][y] != -1)    return memo[k][x][y];
        
        double prob = 0.0;
        // Go eight directions
        prob += dfs(N, K, k + 1, x + 1, y - 2, memo) * ((double)1 / 8);    
        prob += dfs(N, K, k + 1, x + 2, y - 1, memo) * ((double)1 / 8);       
        prob += dfs(N, K, k + 1, x + 2, y + 1, memo) * ((double)1 / 8);
        prob += dfs(N, K, k + 1, x + 1, y + 2, memo) * ((double)1 / 8);     
        prob += dfs(N, K, k + 1, x - 1, y + 2, memo) * ((double)1 / 8);      
        prob += dfs(N, K, k + 1, x - 2, y + 1, memo) * ((double)1 / 8);      
        prob += dfs(N, K, k + 1, x - 2, y - 1, memo) * ((double)1 / 8);     
        prob += dfs(N, K, k + 1, x - 1, y - 2, memo) * ((double)1 / 8);
        
        memo[k][x][y] = prob;
        return prob;
    }
}