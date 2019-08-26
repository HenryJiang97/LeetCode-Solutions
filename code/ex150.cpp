class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            string s = tokens[i];
            
            if (s == "+") {
                int n1 = stk.top();    stk.pop();
                int n2 = stk.top();    stk.pop();
                stk.push(n1 + n2);
            } 
            else if (s == "-") {
                int n1 = stk.top();    stk.pop();
                int n2 = stk.top();    stk.pop();
                stk.push(n2 - n1);
            }
            else if (s == "*") {
                int n1 = stk.top();    stk.pop();
                int n2 = stk.top();    stk.pop();
                stk.push(n1 * n2);
            }
            else if (s == "/") {
                int n1 = stk.top();    stk.pop();
                int n2 = stk.top();    stk.pop();
                stk.push(n2 / n1);
            }
            else {
                stk.push(stoi(s));
            }
        }
        
        return stk.top();
    }
};