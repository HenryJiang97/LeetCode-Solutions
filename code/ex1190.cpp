class Solution {
    int i = 0;
public:
    string reverseParentheses(string s) {
        string res = "";
        while (i < s.length()) {
            if (s[i] == '(') {
                i++;
                res += reverseParentheses(s);
            } else if (s[i] == ')') {
                i++;
                reverse(res.begin(), res.end());
                return res;
            } else {
                res += s[i++];
            }
        }
        return res;
    }
};