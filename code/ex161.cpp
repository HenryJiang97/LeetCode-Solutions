class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.length(), nt = t.length();
        if (ns > nt) {
            string temp = s;
            s = t;
            t = temp;
        }
        
        bool changed = 0;
        int is, it;
        for (is = 0, it = 0; is < ns || it < nt; ) {
            if (s[is] == t[it]) {
                it++;
                is++;
            } else {
                if (ns == nt)    is++;
                it++;
                if (changed)    return 0;
                changed = 1;
            }
        }
        
        return changed;
    }
};