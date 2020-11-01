class Solution {
    int mod = 1e9 + 7;
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].length(), l = target.length();
        vector<unordered_map<char, int>> dict(n, unordered_map<char, int>());
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < n; j++) {
                dict[j][words[i][j]]++;
            }
        }
        
        vector<vector<long>> dp(l + 1, vector<long>(n + 1));
        for (int j = 0; j <= n; j++)    dp[0][j] = 1;
        for (int i = 1; i <= l; i++) {
            char c = target[i - 1];
            for (int j = 1; j <= n; j++) {
                // Not pick current jth char in the dict
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                
                // Pick current jth char in the dict
                if (dict[j - 1].count(c) > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * dict[j - 1][c]) % mod;
                }
            }
        }
        
        return (int)dp[l][n];
    }
};