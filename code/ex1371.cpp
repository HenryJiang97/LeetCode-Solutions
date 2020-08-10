class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        
        vector<char> v{'a', 'e', 'i', 'o', 'u'};
        unordered_set<int> vowels(v.begin(), v.end());
        unordered_map<int, int> map;    map[0] = -1;
        
        int MAX = 0, mask = 0;
        for (int i = 0; i < n; i++) {
            if (vowels.count(s[i]) > 0)
                mask = mask ^ (1 << (s[i] - 'a'));
            if (map.count(mask) > 0)
                MAX = max(MAX, i - map[mask]);
            if (map.count(mask) == 0)
                map[mask] = i;
        }
        
        return MAX;
    }
};