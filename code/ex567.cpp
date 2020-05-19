class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        
        vector<int> target(26);
        for (char c : s1)    target[c - 'a']++;
        
        vector<int> cur(26);
        for (int hi = 0; hi < n2; hi++) {
            cur[s2[hi] - 'a']++;
            if (hi - n1 >= 0)    cur[s2[hi - n1] - 'a']--;
            if (cur == target)    return 1;
        }
        
        return 0;
    }
};