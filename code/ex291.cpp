class Solution {
    int np, ns;
    string pattern, str;
public:
    bool wordPatternMatch(string pattern, string str) {
        np = pattern.length();   ns = str.length();
        this->pattern = pattern;    this->str = str;
        unordered_map<char, string> dict;
        unordered_set<string> used;
        return backtracking(dict, used, 0, 0);
    }
    
private:
    bool backtracking(unordered_map<char, string>& dict, unordered_set<string>& used, int pp, int ps) {
        if (pp == np)    return ps == ns;
        
        bool ret = 0;
        char cur = pattern[pp];
        
        if (dict.find(cur) != dict.end()) {
            string pat = dict[cur];
            if (str.substr(ps, pat.length()) != pat)    return 0;
            return backtracking(dict, used, pp + 1, ps + pat.length());
        }
        else {
            for (int i = ps; i < ns; i++) {
                string s = str.substr(ps, i - ps + 1);
                if (used.find(s) != used.end())    continue;
                dict[cur] = s;
                used.insert(s);
                ret |= backtracking(dict, used, pp + 1, i + 1);
                if (ret)    return 1;
                dict.erase(cur);
                used.erase(s);
            }
        }
        
        return ret;
    }
};