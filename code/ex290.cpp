class Solution {
    vector<string> split(string s) {
        s += ' ';
        vector<string> res;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                res.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        return res;
    }
public:
    bool wordPattern(string pattern, string str) {
        vector<string> arr = split(str);
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        if (pattern.size() != arr.size())    return 0;
        for (int i = 0; i < pattern.size(); i++) {
            char p = pattern[i];
            string s = arr[i];
            if (p2s.count(p) == 0) {
                if (s2p.count(s) > 0)    return 0;
                p2s[p] = s;
                s2p[s] = p;
            } else {
                if (s2p.count(s) == 0)    return 0;
                if (p2s[p] != s || s2p[s] != p)    return 0;
            }
        }
        return 1;
    }
};