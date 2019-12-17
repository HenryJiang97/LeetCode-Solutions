// Sliding window

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        
        // Store the cnt of required chars in t
        unordered_map<char, int> cnt;
        for (char c : t)    cnt[c]++;
        
        string res = s + " ";
        int lo = 0, MIN = s.length();
        unordered_map<char, int> cntWindow;    // Store the cnt of required chars in window
        unordered_set<char> inWindow;    // Char required which meets the cnt in window
        for (int hi = 0; hi < n; hi++) {
            // Move hi 1 place to the right
            if (cnt.find(s[hi]) != cnt.end()) {
                if (++cntWindow[s[hi]] >= cnt[s[hi]])
                    inWindow.insert(s[hi]);
            }
            
            // Try to move lo pointer as right as possible
            while (inWindow.size() == cnt.size() || hi - lo + 1 > res.length()) {
                if (inWindow.size() == cnt.size() && hi - lo + 1 < res.length())
                    res = s.substr(lo, hi - lo + 1);
                if (cnt.find(s[lo]) != cnt.end()) {
                    if (--cntWindow[s[lo]] < cnt[s[lo]])
                        inWindow.erase(s[lo]);
                }
                lo++;
            }
        }
        
        return res == s + " " ? "" : res;
    }
};