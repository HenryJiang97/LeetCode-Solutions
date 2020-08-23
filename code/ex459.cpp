class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i != 0)    continue;
            if (validate(s, i))    return 1;
        }
        return 0;
    }
    
private:
    bool validate(string s, int l) {
        string substring = s.substr(0, l);
        for (int i = l; i < s.length(); i += l)
            if (s.substr(i, l) != substring)    return 0;
        return 1;
    }
};