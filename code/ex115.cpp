class Solution {
public:
    int numDistinct(string s, string t) {
        int nt = t.length(), ns = s.length();
        auto dp = vector<vector<long>>(nt + 1, vector<long>(ns + 1));
        for (int ps = 0; ps <= ns; ps++)    dp[0][ps] = 1;
        
        for (int pt = 1; pt <= nt; pt++) {
            for (int ps = 1; ps <= ns; ps++) {
                if (s[ps - 1] == t[pt - 1])
                    dp[pt][ps] = dp[pt][ps - 1] + dp[pt - 1][ps - 1];
                else
                    dp[pt][ps] = dp[pt][ps - 1];
            }
        }
        
        return dp[nt][ns];
    }
};