class Solution {
public:
    bool validPalindrome(string s) {
        int lo = 0, hi = s.length() - 1;
        
        bool deleted = 0;
        while (lo < hi) {
            if (s[lo] == s[hi]) {
                lo++;
                hi--;
            } else {
                return validate(s, lo + 1, hi) || validate(s, lo, hi - 1);
            }
        }
        
        return 1;
    }
    
private:
    bool validate(string s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--])    return 0;
        }
        return 1;
    }
};