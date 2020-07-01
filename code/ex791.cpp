class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> cnt(26);
        for (char c : T)
            cnt[c - 'a']++;
        
        string res = "";
        for (char c : S) {
            for (int i = 0; i < cnt[c - 'a']; i++) {
                res += c;
            }
            cnt[c - 'a'] = 0;
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                res += (char)('a' + i);
            }
        }
        
        return res;
    }
};