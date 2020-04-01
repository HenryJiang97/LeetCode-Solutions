class Solution {
public:
    int palindromePartition(string s, int K) {
        int n = s.length();
        
        vector<vector<int>> toPalin(n, vector<int>(n, 0));    // Changes to palindrome
        vector<vector<int>> dp(K + 1, vector<int>(n, INT_MAX / 2));
        
        // Get the minimum changes to palindrome
        changeToPalindrome(toPalin, s);
        
        // Build dp array
        for (int i = 0; i < n; i++)    dp[1][i] = toPalin[0][i];
        for (int k = 2; k <= K; k++) {
            for (int i = k - 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    dp[k][i] = min(dp[k][i], dp[k - 1][j] + toPalin[j + 1][i]);
                }
            }
        }
        
        return dp[K][n - 1];
    }
    
private:
    void changeToPalindrome(vector<vector<int>>& toPalin, string s) {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int lo = i, hi = j;
                while (lo < hi) {
                    if (s[lo] != s[hi])    toPalin[i][j]++;
                    lo++;    hi--;
                }
            }
        }
    }
};