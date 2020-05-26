class Solution {
public:
    int calculate(string s) {
        s += '+';
        
        int num = 0, sign = 1;
        stack<int> stk;
        char operation = ' ';
        for (char c : s) {
            if (isdigit(c) || c == ' ') {
                if (isdigit(c))    num = num * 10 + (c - '0');
            }
            else {
                if (operation != ' ') {
                    int out = stk.top();    stk.pop();
                    if (operation == '*')    stk.push(out * (sign * num));
                    else    stk.push(out / (sign * num));
                    operation = ' ';
                } else {
                    stk.push(sign * num);    
                }
                num = 0;
                sign = 1;
                
                if (c == '+')    sign = 1;
                else if (c == '-')    sign = -1;
                else if (c == '*')    operation = '*';
                else if (c == '/')    operation = '/';
            } 
        }
        
        // Get result
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        
        return sum;
    }
};