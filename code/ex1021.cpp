class Solution {
public:
    string removeOuterParentheses(string S) {
        int open = 0;
        string temp = "", res = "";
        for (char c : S) {
            if (c == '(')    open++;
            if (open >= 2)    temp += c;
            if (c == ')')    open--;
            if (open == 0) {
                res += temp;
                temp = "";
            }
        }
        return res;
    }
};