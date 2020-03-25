class Solution {
public:
    string parseTernary(string expression) {
        stack<char> stk;
        
        for (int i = expression.length() - 1; i >= 0; i--) {
            char c = expression[i];
            if (!stk.empty() && stk.top() == '?') {
                stk.pop();    // "?"
                int first = stk.top();    stk.pop();
                stk.pop();    // ":"
                int second = stk.top();    stk.pop();
                if (c == 'T')    stk.push(first);
                else    stk.push(second);
            } else {
                stk.push(c);
            }
        }
        
        return string(1, stk.top());
    }
};