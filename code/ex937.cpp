// Custom sort

class Solution {
    struct cmp {
        bool operator()(string a, string b) {
            auto sa = splitBySpace(a);
            auto sb = splitBySpace(b);
            
            // Sort the log by lexical order
            for (int i = 1; i < min(sa.size(), sb.size()); i++) {
                if (sa[i] != sb[i]) {
                    return sa[i] < sb[i];
                }
            }
            
            if (sa.size() != sb.size())    return sa.size() < sb.size();
            else    return (sa[0] < sb[0]);    // If lexical order of two strings is same, sort by the identifier
        }
        
        vector<string> splitBySpace(string s) {
            int n = s.length();
            vector<string> res = vector<string>();

            string temp = "";
            for (int i = 0; i < n; i++) {
                if (s[i] == ' ') {
                    res.push_back(temp);
                    temp = "";
                } else {
                    temp += s[i];
                }
            }
            res.push_back(temp);

            return res;
        }
    };
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterlog, digitlog;
        for (string s : logs) {
            if (isdigit(s[s.find(" ") + 1]))    digitlog.push_back(s);
            else    letterlog.push_back(s);
        }
        sort(letterlog.begin(), letterlog.end(), cmp());
        
        vector<string> res;
        for (string s : letterlog)    res.push_back(s);
        for (string s : digitlog)    res.push_back(s);
        
        return res;
    }
};