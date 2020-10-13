class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        for (string a : A) {
            vector<int> cur(26);
            for (char c : a) {
                cur[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                cnt[i] = min(cur[i], cnt[i]);
            }
        }
        
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                char c = 'a' + i;
                string s = "";
                res.push_back(s + c);
            }
        }
        return res;
    }
};