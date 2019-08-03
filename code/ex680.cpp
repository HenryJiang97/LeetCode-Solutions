class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();    if (n <= 1)    return true;
        
        int del = 0;
        
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++;    hi--;
            } else {
                if (del != 0)    return false;
                else {
                    if (varify(s, lo + 1, hi) || varify(s, lo, hi - 1))    return true;
                    else    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool varify(string s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] != s[hi])    return false;
            lo++;    hi--;
        }
        return true;
    }
};