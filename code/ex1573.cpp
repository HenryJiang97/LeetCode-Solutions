class Solution {
public:
    int numWays(string s) {
        const int mod = 1e9 + 7;
        
        int n = s.length(), ones = 0;
        for (char c : s)    ones += c == '1' ? 1 : 0;
        if (ones % 3 != 0)    return 0;
        int part = ones / 3;
        if (part == 0)    return (int)((long)(1 + n - 2) * (n - 2) / 2 % mod);
        
        long first = 0, third = 0;
        for (int i = 0, cnt1 = 0, cnt2 = 0; i < n; i++) {
            cnt1 += s[i] == '1' ? 1 : 0;
            if (cnt1 == part)    first++;
            int j = n - i - 1;
            cnt2 += s[j] == '1' ? 1 : 0;
            if (cnt2 == part)    third++;
        }
        
        return (int)(first * third % mod);
    }
};