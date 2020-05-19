class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        
        int mask = 0, MAX = 0;
        unordered_map<int, int> m;
        m[mask] = -1;
        
        for (int z = 0; z < n; ++z) {
            char c = s[z];
            if (c == 'a')    mask ^= (1 << 0);
            else if (c == 'e')    mask ^= (1 << 1);
            else if (c == 'i')    mask ^= (1 << 2);
            else if (c == 'o')    mask ^= (1 << 3);
            else if (c == 'u')    mask ^= (1 << 4);
            
            if (m.count(mask) != 0)
                MAX = max(MAX, z - m[mask]);
            else
                m[mask] = z;
        }
        
        return MAX;
    }
};