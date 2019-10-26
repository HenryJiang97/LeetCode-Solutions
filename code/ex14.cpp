class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)    return "";
        
        int minLen = INT_MAX;
        for (string str : strs) {
            int n = str.length();
            minLen = min(minLen, n);
        }
        
        for (int i = 0; i < minLen; i++) {
            bool match = 1;
            char c = strs[0][i];
            for (string s : strs) {
                if (s[i] != c) {
                    match = 0;
                    break;
                }
            }
            if (!match)
                return strs[0].substr(0, i);
        }
        
        return strs[0].substr(0, minLen);
    }
};