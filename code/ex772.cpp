typedef long long ll;

class Solution {
public:
    int calculate(string s) {
        queue<char> que;
        for (char c : s)
            if (c != ' ')    que.push(c);
        que.push('+');    // End sign
        return cal(que);
    }
    
private:
    int cal(queue<char>& que) {
        char sign = '+';
        ll num = 0;
        stack<ll> stk;
        
        while (!que.empty()) {
            char c = que.front();    que.pop();
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '(') {
                num = cal(que);
            }
            else {    // When meets operators or ')', get the result of last part
                if (sign == '+')
                    stk.push(num);
                else if (sign == '-')
                    stk.push(-num);
                else if (sign == '*') {
                    int last = stk.top();    stk.pop();
                    stk.push(last * num);
                } else if (sign == '/') {
                    int last = stk.top();     stk.pop();;
                    stk.push(last / num);
                }
                num = 0;
                sign = c;
                if (c == ')')    break;
            }
        }
        
        ll sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        
        return (int)sum;
    }
};