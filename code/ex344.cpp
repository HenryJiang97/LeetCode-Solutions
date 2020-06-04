class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            char t = s[lo];
            s[lo++] = s[hi];
            s[hi--] = t;
        }
    }
};