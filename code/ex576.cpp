const int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const int mod = 1e9 + 7;

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> memo(N + 1, vector<vector<int>>(m, vector<int>(n, -1)));
        return dfs(m, n, i, j, N, memo);
    }
    
private:
    int dfs(int m, int n, int i, int j, int N, vector<vector<vector<int>>>& memo) {
        if (i < 0 || j < 0 || i >= m || j >= n)    return 1;
        if (N <= 0)    return 0;
        if (memo[N][i][j] != -1)    return memo[N][i][j];
        int total = 0;
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            total = (total + dfs(m, n, ni, nj, N - 1, memo)) % mod;
        }
        memo[N][i][j] = total;
        return total;
    }
};