class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        
        int cnt = n;
        auto dp = vector<vector<bool>>(n, vector<bool>(n));
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j])    dp[i][j] = i + 1 <= j - 1 ? dp[i + 1][j - 1] : 1;
                if (dp[i][j])    cnt++;
            }
        }
        
        return cnt;
    }
};