class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)    return 1;
        
        // Judge if two string can be same after scrambled
        int n = s1.length();
        int dict[26] = {0};
        for (int i = 0; i < n; i++) {
            dict[s1[i] - 'a']++;
            dict[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (dict[i] != 0)    return 0;
        
        // Recurrsion to subtrees
        for (int i = 0; i < n - 1; i++) {
            if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)))
                return 1;
            if (isScramble(s1.substr(0, i + 1), s2.substr(n - i - 1, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(0, n - i - 1)))
                return 1;
        }
        
        return 0;
    }
};