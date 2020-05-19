class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.length();
        
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        int MAX = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        
        for (int z = 0; z < n; ++z) {
            char c = s[z];
            if (c == 'a')    a++;
            else if (c == 'e')    e++;
            else if (c == 'i')    i++;
            else if (c == 'o')    o++;
            else if (c == 'u')    u++;
            int mask = getMask(a, e, i, o, u);
            if (m.find(mask) != m.end())
                MAX = max(MAX, z - m[mask]);
            else
                m[mask] = z;
        }
        
        return MAX;
    }
    
private:
    int getMask(int a, int e, int i, int o, int u) {
        int mask = 0;
        mask |= ((a % 2) << 0);
        mask |= ((e % 2) << 1);
        mask |= ((i % 2) << 2);
        mask |= ((o % 2) << 3);
        mask |= ((u % 2) << 4);
        return mask;
    }
};