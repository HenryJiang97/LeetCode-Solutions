class Solution {
public:
    int balancedString(string s) {
        int n = s.length() / 4;
        vector<int> dict(26);
        for (char c : s)
            dict[c - 'A']++;
        
        int MIN = INT_MAX, lo = 0;
        for (int hi = 0; hi < n * 4 ; hi++) {
            dict[s[hi] - 'A']--;
            while (lo < n * 4 && dict[16] <= n && dict[22] <= n && dict[4] <= n && dict[17] <= n) {
                MIN = min(MIN, hi - lo + 1);
                dict[s[lo++] - 'A']++;
            }
        }
        
        return MIN;
    }
};