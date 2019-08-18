// DP

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        unordered_set<string> set;
        for (string word : wordDict)    set.insert(word);
        
        // Init dp array
        vector<bool> dp(n + 1);
        dp[0] = true;
        
        // Build dp array
        for (int i = 0; i < n; i++) {
            if (!dp[i])    continue;
            for (int j = i; j < n; j++) {
                if (set.find(s.substr(i, j - i + 1)) != set.end())
                    dp[j + 1] = true;
            }
        }
        
        return dp[n];
    }
};