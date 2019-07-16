class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        
        auto dp = vector<vector<int>>(n, vector<int>(n, 0));
        
        // Init
        for (int i = 0; i < n; i++)    dp[i][i] = 1;
        cnt += n;
        
        // Build dp array
        for (int l = 2; l <= n; l++) {
            for (int start = 0; start <= n - l; start++) {
                int lo = start, hi = start + l - 1;
                
                if (s[lo] == s[hi]) {
                    if (hi == lo + 1)    dp[lo][hi] = 1;
                    else    dp[lo][hi] = dp[lo + 1][hi - 1];
                }
                
                cnt += dp[lo][hi];
            }
        }

        return cnt;
    }
};