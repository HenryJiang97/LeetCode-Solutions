class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.length();
        unordered_map<char, int> charCnt;
        unordered_map<string, int> strCnt;
        for (int i = 0; i < minSize; i++) {
            charCnt[s[i]]++;
        }
        if (charCnt.size() <= maxLetters)    strCnt[s.substr(0, minSize)]++;
        
        for (int hi = minSize; hi < n; hi++) {
            int lo = hi - minSize;
            charCnt[s[hi]]++;
            if (--charCnt[s[lo]] == 0)    charCnt.erase(s[lo]);
            if (charCnt.size() <= maxLetters)    strCnt[s.substr(lo + 1, minSize)]++;
        }
        
        int MAX = 0;
        for (auto& [k, v] : strCnt) {
            MAX = max(MAX, v);
        }
        return MAX;
    }
};