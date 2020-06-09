class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)    return 0;
        string s = to_string(x);
        int lo = 0, hi = s.length() - 1;
        while (lo < hi) {
            if (s[lo++] != s[hi--])
                return 0;
        }
        return 1;
    }
};