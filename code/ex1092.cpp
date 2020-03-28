class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        string lcs = LCS(str1, str2);
        string res = "";
        int p1 = 0, p2 = 0;
        for (char c : lcs) {
            while (str1[p1] != c)    res += str1[p1++];
            while (str2[p2] != c)    res += str2[p2++];
            res += c;
            p1++;    p2++;
        }
        while (p1 < n1)    res += str1[p1++];
        while (p2 < n2)    res += str2[p2++];
        return res;
    }
    
private:
    string LCS(string s1, string s2) {    // Get the longest common subsequence
        int n1 = s1.length(), n2 = s2.length();
        vector<vector<string>> dp(n1 + 1, vector<string>(n2 + 1));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                else
                    dp[i][j] = dp[i - 1][j].length() >= dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
        return dp[n1][n2];
    }
};