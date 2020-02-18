class Solution {
public:
    bool canWin(string s) {
        int n = s.length();
        bool win = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != '+' || s[i + 1] != '+')    continue;
            s[i] = '-';    s[i + 1] = '-';
            if (!canWin(s))    {win = 1;    break;}
            s[i] = '+';    s[i + 1] = '+';
        }
        return win;
    }
};