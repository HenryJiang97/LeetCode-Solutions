class Solution {
public:
    int calculate(string s) {
        queue<char> que;
        for (char c : s)
            if (c != ' ')    que.push(c);
        que.push('+');
        
        int temp = 0;
        char sign = '+';
        stack<int> stk;
        while (!que.empty()) {
            char c = que.front();    que.pop();
            if (isdigit(c)) {
                temp = temp * 10 + (c - '0');
            } else {
                switch (sign) {
                    int out;
                    case '+':
                        stk.push(temp);
                        break;
                    case '-':
                        stk.push(-temp);
                        break;
                    case '*':
                        out = stk.top();    stk.pop();
                        stk.push(out * temp);
                        break;
                    case '/':
                        out = stk.top();    stk.pop();
                        stk.push(out / temp);
                        break;
                }
                temp = 0;
                sign = c;
            }
        }
        
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};