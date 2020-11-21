class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cnts(26), cntt(26);
        for (char c : s)    cnts[c - 'a']++;
        for (char c : t)    cntt[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (cnts[i] != cntt[i])    return 0;
        }
        return 1;
    }
};