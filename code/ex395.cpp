class Solution {
public:
    int longestSubstring(string s, int k) {
        vector<int> cnt(26);
        for (char c : s)    cnt[c - 'a']++;
        int lo = 0, hi = 0, MAX = 0;
        bool valid = 1;
        while (hi < s.length()) {
            if (cnt[s[hi] - 'a'] < k) {
                MAX = max(MAX, longestSubstring(s.substr(lo, hi - lo), k));
                valid = 0;
                lo = hi + 1;
            }
            hi++;
        }
        return valid ? s.length() : max(MAX, longestSubstring(s.substr(lo, s.length() - lo), k));
    }
};