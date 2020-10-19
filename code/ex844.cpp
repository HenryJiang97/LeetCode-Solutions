class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int ps = s.length() - 1, pt = t.length() - 1;
        int skipS = 0, skipT = 0;
        while (ps >= 0 || pt >= 0) {
            while (ps >= 0) {    // Skip deleted chars
                if (s[ps] == '#') {skipS++;    ps--;}
                else if (skipS > 0) {ps--;    skipS--;}
                else    break;
            }
            while (pt >= 0) {    // Skip deleted chars
                if (t[pt] == '#') {skipT++;    pt--;}
                else if (skipT > 0) {pt--;    skipT--;}
                else    break;
            }
            if (ps >= 0 && pt >= 0 && s[ps] != t[pt]) {    // Char not match
                return 0;
            }
            if (ps >= 0 != pt >= 0) {    // Only one of the strings is ended
                return 0;
            }
            ps--;    pt--;
        }
        return 1;
    }
};