// dp[i][j] => the operations needed to change to word1.substring(0, i) to word2.substring(0, j)

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        auto dp = vector<vector<int>>(n1 + 1, vector<int>(n2 + 1));
        // Init dp array
        for (int i = 0; i <= n1; i++)    dp[i][0] = i;
        for (int j = 0; j <= n2; j++)    dp[0][j] = j;
        // Build dp array
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]) + 1, dp[i - 1][j - 1]);
                else
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[n1][n2];
    }
};