class Solution {
public:
    string pushDominoes(string d) {
        d = 'L' + d + 'R';
        string res = "";
        for (int lo = 0, hi = 1; hi < d.length(); hi++) {
            if (d[hi] == '.')    continue;
            int gap = hi - lo - 1;
            res += d[lo];
            if (d[lo] == d[hi])    res += string(gap, d[lo]);
            else if (d[lo] == 'L' && d[hi] == 'R')    res += string(gap, '.');
            else    res += string(gap / 2, 'R') + string(gap % 2, '.') + string(gap / 2, 'L');
            lo = hi;
        }
        return res.substr(1);
    }
};