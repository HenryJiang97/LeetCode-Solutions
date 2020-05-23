class Solution {
public:
    int findIntegers(int num) {
        string snum = getReverseBinary(num);
        int n = snum.length();
        
        // DP to find possible number of binary representations
        vector<vector<int>> dp(n, vector<int>(2));    // {end with 0, end with 1}
        dp[0][0] = 1;    dp[0][1] = 1;
        
        for (int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }
        
        // Remove some possibilities which could be larger than num
        int res = dp[n - 1][0] + dp[n - 1][1];
        for (int i = n - 2; i >= 0; i--) {
            if (snum[i] == '1' && snum[i + 1] == '1')    break;
            if (snum[i] == '0' && snum[i + 1] == '0')    res -= dp[i][1];
        }
        
        return res;
    }
    
private:
    string getReverseBinary(int num) {    // Get the reverse binary representation of the num
        string s = "";
        while (num > 0) {
            s += to_string(num % 2);
            num /= 2;
        }
        return s;
    }
};