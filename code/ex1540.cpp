class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length())    return 0;
        int n = s.length();
        
        // Get cnt for each move
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                map[(t[i] - s[i] + 26) % 26]++;
            }
        }
        
        // Get the maximum move each char would need
        int MAX = 0;
        for (auto& [k, v] : map) {
            MAX = max(MAX, k + (v - 1) * 26);
        }
        
        return MAX <= k;
    }
};