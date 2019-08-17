typedef long long ll;

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        
        ll res = 0;
        stack<ll> stk_res, stk_sign;
        ll num = 0, sign = 1;
        int i = 0;
        
        while (i < n) {
            char c = s[i];
            
            // Cases:
            if (c == '+') {
                res += sign * num;
                num = 0;    sign = 1;
            }
            else if (c == '-') {
                res += sign * num;
                num = 0;    sign = -1;
            }
            
            else if (c == '(') {
                stk_res.push(res);
                stk_sign.push(sign);
                res = 0;    sign = 1;
            }
            
            else if (c == ')') {
                if (num != 0)    res += sign * num;
                num = 0;
                res = res * stk_sign.top() + stk_res.top();
                stk_sign.pop();    stk_res.pop();
            }
            
            else if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            
            i++;
        }
        
        if (num != 0)    res += sign * num;
        
        return (int)res;
    }
};