class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dict;
        for (char c : s)    dict[c]++;
        int cnt = 0;
        for (auto entry : dict)
            if (entry.second % 2 == 1)    cnt++;
        return cnt <= 1;
    }
};