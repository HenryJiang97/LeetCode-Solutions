// Stack

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> stack;    stack.push(-1);
        
        int MAX = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')    stack.push(i);
            else if (s[i] == ')') {
                stack.pop();
                if (!stack.empty()) {
                    MAX = max(MAX, i - stack.top());
                } else {
                    stack.push(i);
                }
            }
        }
        
        return MAX == INT_MIN ? 0 : MAX;
    }
};