// Notice that s is in alphabatical order
// Just need to find the longest subsequence ends with each letter following the alphabatical order in p

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.length() <= 1)    return p.length();
        
        auto dp = vector<int>(26);  // dp[i] save the max length of substring ends with i + 'a'
        dp[p[0] - 'a'] = 1;
        
        int len = 1;
        for (int i = 1; i < p.length(); i++) {
            if (p[i] - p[i - 1] == 1 || p[i] - p[i - 1] == -25)    len++;
            else    len = 1;
            
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);
        }
        
        return accumulate(dp.begin(), dp.end(), 0);
    }
};