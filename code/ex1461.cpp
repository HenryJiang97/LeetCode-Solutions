class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();    if (k > n)    return 0;
        unordered_set<int> set;
        
        int mask = 0;
        for (int i = 0; i < k; i++)    mask = (mask << 1) + (s[i] - '0');
        set.insert(mask);
        for (int hi = k; hi < n; hi++) {
            int lo = hi - k;
            mask -= ((s[lo] - '0') << (k - 1));
            mask = (mask << 1) + (s[hi] - '0');
            set.insert(mask);
        }
        
        return set.size() == (1 << k);
    }
};