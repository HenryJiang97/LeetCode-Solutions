// DFS with memo

class Solution {
public:  
    int mod = pow(10, 9) + 7;
    int knightDialer(int N) {
        if (N == 0)    return 10;
        vector<vector<int>> hop{{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        
        int cnt = 0;
        vector<vector<int>> memo(N, vector<int>(10));
        for (int i = 0; i <= 9; i++) {
            cnt += dfs(hop, N, 1, i, memo);
            cnt %= mod;
        }
        return cnt;
    }
    
    int dfs(vector<vector<int>>& hop, int N, int n, int start, vector<vector<int>>& memo) {
        if (n == N)    return 1;
        int cnt = 0;
        // Load memo
        if (memo[n][start] != 0)    return memo[n][start];
        for (auto a : hop[start]) {
            cnt += dfs(hop, N, n + 1, a, memo);
            cnt %= mod;
        }
        // Save to memo
        memo[n][start] = cnt;
        return cnt;
    }
};
