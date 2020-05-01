class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> set;
        int MAX = 0, lo = 0, hi = 0;
        while (hi < n) {
            char chi = s[hi];
            while (lo < hi && set.find(chi) != set.end()) {
                set.erase(s[lo++]);
            }
            MAX = max(MAX, hi - lo + 1);
            set.insert(s[hi++]);
        }
        return MAX;
    }
};