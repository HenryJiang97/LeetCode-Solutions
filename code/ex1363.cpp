class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), greater<int>());
        int n = digits.size();
        
        int dp[n + 1][3];    // max length
        int prev[n + 1][3];
        bool picked[n + 1][3];
        dp[0][0] = 0;    dp[0][1] = INT_MIN;    dp[0][2] = INT_MIN;
        
        for (int i = 1; i <= n; i++) {
            for (int m = 0; m < 3; m++) {
                if (dp[i - 1][m] >= dp[i - 1][(m - digits[i - 1] % 3 + 3) % 3] + 1) {    // Skip
                    dp[i][m] = dp[i - 1][m];
                    picked[i][m] = 0;
                    prev[i][m] = m;
                } else {    // Pick
                    dp[i][m] = dp[i - 1][(m - digits[i - 1] % 3 + 3) % 3] + 1;
                    picked[i][m] = 1;
                    prev[i][m] = (m - digits[i - 1] % 3 + 3) % 3;
                }
            }
        }
        
        // Backtrack
        string res = "";
        for (int i = n, j = 0; i > 0; i--) {
            if (picked[i][j]) {
                res += to_string(digits[i - 1]);
            }
            j = prev[i][j];
        }
        reverse(res.begin(), res.end());
        
        // Remove prefix zeros
        int p = 0;
        while (p < res.length() - 1 && res[p] == '0')    p++;
        return res.substr(p);
    }
};