// DP, dp[i] => the length of longest substring of lvp ending at i

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        
        int MAX = 0;
        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    // For single parenthese cases: '...()'
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                if (s[i - 1] == ')' && i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                    // For nested and complex parenthese cases: '...)()())'
                    dp[i] = ((i - dp[i - 1] - 2) >= 0 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
                }
            }
            MAX = max(MAX, dp[i]);
        }
        
        return MAX;
    }
};