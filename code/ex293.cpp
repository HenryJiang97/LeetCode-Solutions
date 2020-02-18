class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int n = s.length();
        vector<string> res;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-';    s[i + 1] = '-';
                res.push_back(s);
                s[i] = '+';    s[i + 1] = '+';
            }
        }
        return res;
    }
};