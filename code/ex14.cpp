class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)    return "";
        string prefix = "";
        int p = 0;
        while (1) {
            if (p >= strs[0].length())    return prefix;
            char c = strs[0][p];
            for (string s : strs) {
                if (p >= s.length() || s[p] != c)    return prefix;
            }
            prefix += c;
            p++;
        }
        return prefix;
    }
};