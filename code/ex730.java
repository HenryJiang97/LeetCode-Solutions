// 2D-DP: dp[i][j] += dp[next[i][k] + 1][prev[i][k] - 1] + 1    (if there's matched head and tail palindrom within i and j)

class Solution {
    public int countPalindromicSubsequences(String S) {
        int n = S.length();
        int mod = (int)1e9 + 7;
        
        // Build next and prev array storing the next index of 'a', 'b', 'c', 'd' after i
        int[][] next = new int[n][4];    
        int[][] prev = new int[n][4];
        
        int[] index = new int[4];    Arrays.fill(index, -1);
        for (int i = 0; i < n; i++) {
            char c = S.charAt(i);
            index[c - 'a'] = i;
            for (int k = 0; k < 4; k++) {
                prev[i][k] = index[k];
            }
        }
        
        Arrays.fill(index, n);
        for (int i = n - 1; i >= 0; --i) {
            char c = S.charAt(i);
            index[c - 'a'] = i;
            for (int k = 0; k < 4; k++) {
                next[i][k] = index[k];
            }
        }
        
        // Define dp array, dp[i][j] => the count of different palindromic subsequences within [i:j]
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        
        // Build dp array
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                
                for (int k = 0; k < 4; k++) {
                    if (next[i][k] < prev[j][k]) {
                        dp[i][j] += dp[next[i][k] + 1][prev[j][k] - 1] + 1;
                    }
                    if (next[i][k] <= j) {
                        dp[i][j]++;
                    }
                    
                    dp[i][j] %= mod;
                }
            }
        }
        
        return dp[0][n - 1];
    }
}