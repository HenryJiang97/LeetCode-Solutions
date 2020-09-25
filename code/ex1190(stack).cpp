class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        string temp = "";
        for (char c : s) {
            if (c == '(') {
                stk.push(temp);
                temp = "";
            } else if (c == ')') {
                reverse(temp.begin(), temp.end());
                string prev = stk.top();    stk.pop();
                prev += temp;
                temp = prev;
            } else {
                temp += c;
            }
        }
        return temp;
    }
};