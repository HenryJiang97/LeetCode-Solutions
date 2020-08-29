class Solution {
    int mod = 1e9 + 7, m, n;
    vector<string> pizza;
public:
    int ways(vector<string>& pizza, int k) {
        this->pizza = pizza;
        m = pizza.size(), n = pizza[0].length();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
        for (int i = m - 1; i >= 0; i--)
            for (int j = n - 1; j >= 0; j--)
                prefix[i][j] = prefix[i][j + 1] + prefix[i + 1][j] - prefix[i + 1][j + 1] + (pizza[i][j] == 'A');
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(k, -1)));
        return backtracking(0, 0, k - 1, prefix, memo);
    }

private:
    int backtracking(int i, int j, int k, vector<vector<int>>& prefix, vector<vector<vector<int>>>& memo) {
        if (k == 0)    return 1;
        if (memo[i][j][k] != -1)    return memo[i][j][k];
        
        int cnt = 0;
        // Horizontal cut
        for (int ii = i; ii < m - 1; ii++) {
            int down = prefix[ii + 1][j]; 
            int up = prefix[i][j] - down;
            if (down < 1 || up < 1)    continue;
            cnt = (cnt + backtracking(ii + 1, j, k - 1, prefix, memo)) % mod;
        }
        
        // Vertical cut
        for (int jj = j; jj < n - 1; jj++) {
            int right = prefix[i][jj + 1];
            int left = prefix[i][j] - right;
            if (left < 1 || right < 1)    continue;
            cnt = (cnt + backtracking(i, jj + 1, k - 1, prefix, memo)) % mod;
        }
        
        memo[i][j][k] = cnt;
        return cnt;
    }
};