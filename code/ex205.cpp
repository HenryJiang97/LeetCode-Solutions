class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> dict;
        unordered_set<char> used;
        for (int i = 0; i < s.length(); i++) {
            if (dict.count(s[i]) > 0) {
                if (t[i] != dict[s[i]])    return 0;
            } else {
                if (used.count(t[i]) > 0)    return 0;
                dict[s[i]] = t[i];
                used.insert(t[i]);
            }
        }
        return 1;
    }
};