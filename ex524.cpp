// Brute force

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int len = 0;
        string res = "";
        for (auto str : d) {
            if (str.length() > len && ifSubsequence(s, str)) {
                len = str.length();
                res = str;
            }
            if (str.length() == len && str < res && ifSubsequence(s, str))
                res = str;
        }
        
        return res;
    }

private:
    bool ifSubsequence(string s, string d) {
        int ps = 0, pd = 0;
        while (pd < d.length()) {
            if (s[ps] == d[pd]) {
                ps++;    pd++;
            } else    ps++;
            if (ps >= s.length())    break;
        }
        if (ps >= s.length() && pd < d.length())    return false;
        else    return true;
    }
};