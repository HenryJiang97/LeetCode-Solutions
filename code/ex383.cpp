class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dict[26] = {0};
        for (char c : magazine)    dict[c - 'a']++;
        for (char c : ransomNote)
            if (--dict[c - 'a'] < 0)    return 0;
        return 1;
    }
};