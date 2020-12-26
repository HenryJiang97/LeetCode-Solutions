class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = max(0, i - 2); j < i; j++) {
                string ss = s.substr(j, i - j);
                if (valid(ss))    dp[i] += dp[j];
            }
        }
        return dp.back();
    }
    
private:
    bool valid(string s) {
        int n = s.length();
        if (n == 1)    return s > "0" && s <= "9";
        else    return s >= "10" && s <= "26";
    }
};