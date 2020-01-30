class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())    return 0;
        unordered_map<char, int> dict;
        for (char c : s1)    dict[c]++;
        
        // Sliding window to find required num of chars in s2
        unordered_map<char, int> cntWindow;
        unordered_set<char> inWindow;
        for (int i = 0; i < s1.length(); i++) {
            char c = s2[i];
            if (dict.count(c) > 0) {
                if (++cntWindow[c] >= dict[c])    inWindow.insert(c);
            }
        }
        if (inWindow.size() == dict.size())    return 1;
        int lo = 0;
        for (int hi = s1.length(); hi < s2.length(); hi++) {
            if (dict.count(s2[hi]) > 0)
                if (++cntWindow[s2[hi]] >= dict[s2[hi]])    inWindow.insert(s2[hi]);
            if (dict.count(s2[lo]) > 0)
                if (--cntWindow[s2[lo]] < dict[s2[lo]])    inWindow.erase(s2[lo]);
            lo++;
            if (inWindow.size() == dict.size())    return 1;
        }
        
        return 0;
    }
};