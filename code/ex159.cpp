// Sliding window

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        
        unordered_map<char, int> cnt;
        int lo = 0, hi = 0;
        int maxLen = 0;
        while (hi < n) {
            cnt[s[hi]]++;
            while (cnt.size() > 2) {
                if (--cnt[s[lo]] == 0)    cnt.erase(s[lo]);
                lo++;
            }
            if (cnt.size() <= 2)    maxLen = max(maxLen, hi - lo + 1);
            hi++;
        }
        
        return maxLen;
    }
};