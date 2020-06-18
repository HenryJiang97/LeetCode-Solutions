class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (!isalpha(s[lo]) && !isdigit(s[lo]))    {lo++;    continue;}
            if (!isalpha(s[hi]) && !isdigit(s[hi]))    {hi--;    continue;}
            if (isdigit(s[lo]) && isdigit(s[hi]) && s[lo] == s[hi] ||
               isalpha(s[lo]) && isalpha(s[hi]) && toupper(s[lo]) == toupper(s[hi])) {
                lo++;    hi--;
            } else {
                return 0;
            }
        }
        return 1;
    }
};