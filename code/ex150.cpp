class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<string> signs{"+", "-", "*", "/"};
        unordered_set<string> set(signs.begin(), signs.end());
        stack<int> stk;
        for (string s : tokens) {            
            if (set.count(s) > 0) {
                int p2 = stk.top();    stk.pop();
                int p1 = stk.top();    stk.pop();
                if (s == "*")    stk.push(p1 * p2);
                if (s == "/")    stk.push(p1 / p2);
                if (s == "+")    stk.push(p1 + p2);
                if (s == "-")    stk.push(p1 - p2);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};