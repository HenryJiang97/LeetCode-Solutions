class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                rev(s, lo, hi);
                lo = i + 1;
            } else
                hi = i;
        }
        rev(s, lo, hi);
        
        return s;
    }
    
private:
    void rev(string &s, int lo, int hi) {
        while (lo < hi) {
            char temp = s[lo];    s[lo] = s[hi];    s[hi] = temp;
            lo++;    hi--;
        }
    }
};