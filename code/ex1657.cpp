class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> cnt1;
        for (char c : word1)    cnt1[c]++;
        unordered_map<char, int> cnt2;
        for (char c : word2)    cnt2[c]++;
        for (char c : word2) {
            if (cnt1.count(c) == 0)    return 0;
        }
        unordered_map<int, int> map1;
        for (auto& [k, v] : cnt1)    map1[v]++;
        for (auto& [k, v] : cnt2) {
            if (map1.count(v) == 0)    return 0;
            if (--map1[v] == 0)    map1.erase(v);
        }
        return 1;
    }
};