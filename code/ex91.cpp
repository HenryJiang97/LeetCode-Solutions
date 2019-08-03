// DP: dp[i] => dp[i + 1] + (substring of [i, i + 1] is between 1 and 26) ? dp[i + 2] : 0

class Solution {
public:
    int numDecodings(string s) {
        // Corner cases
        int n = s.length();
        if (n == 0)    return 0;
        if (n == 1)    return s[0] == '0' ? 0 : 1;
        
        // Build dp array
        int dp[n + 1] = {0};    dp[n - 1] = s[n - 1] == '0' ? 0 : 1;    dp[n] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '0')    {dp[i] = 0;    continue;}    // If the current char is '0', break string into two parts
            dp[i] += dp[i + 1];
            dp[i] += (stoi(s.substr(i, 2)) <= 26 && stoi(s.substr(i, 2)) >= 1) ? dp[i + 2] : 0;
        }

        return dp[0];
    }
};