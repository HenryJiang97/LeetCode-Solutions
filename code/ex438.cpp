class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.length(), np = p.length();
        
        vector<int> target(26);
        for (char c : p)    target[c - 'a']++;
        
        vector<int> res;
        vector<int> cur(26);
        for (int hi = 0; hi < ns; hi++) {
            cur[s[hi] - 'a']++;
            if (hi - np >= 0)    cur[s[hi - np] - 'a']--;
            if (cur == target)    res.push_back(hi - np + 1);
        }
        
        return res;
    }
};