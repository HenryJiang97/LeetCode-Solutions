class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            while (lo < hi && !isalpha(s[lo]) && !isdigit(s[lo]))    lo++;
            while (lo < hi && !isalpha(s[hi]) && !isdigit(s[hi]))    hi--;
            if (tolower(s[lo++]) != tolower(s[hi--]))    return 0;
        }
        return 1;
    }
};