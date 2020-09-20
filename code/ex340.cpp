class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        
        unordered_map<int, int> cnt;
        int MAX = 0, lo = 0, hi = 0;
        while (hi < n) {
            cnt[s[hi]]++;
            while (cnt.size() > k) {
                if (--cnt[s[lo]] == 0)    cnt.erase(s[lo]);
                lo++;
            }
            MAX = max(MAX, hi - lo + 1);
            hi++;
        }
        
        return MAX;
    }
};