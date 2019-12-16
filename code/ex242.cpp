class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cnt;
        for (char c : s)    cnt[c]++;
        for (char c : t) {
            if (cnt.find(c) == cnt.end())    return 0;
            cnt[c]--;
        }
        for (auto entry : cnt)
            if (entry.second != 0)    return 0;
        return 1;
    }
};