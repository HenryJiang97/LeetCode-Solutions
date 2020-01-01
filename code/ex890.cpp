class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for (string word : words) {
            unordered_map<char, char> map;
            unordered_set<char> used;
            bool match = 1;
            for (int i = 0; i < word.length(); i++) {
                if (map.find(word[i]) == map.end()) {
                    if (used.find(pattern[i]) != used.end()) {
                        match = 0;    break;
                    }
                    map[word[i]] = pattern[i];
                    used.insert(pattern[i]);
                }
                else if (pattern[i] != map[word[i]]) {
                    match = 0;    break;
                }
            }
            if (match)    res.push_back(word);
        }
        return res;
    }
};