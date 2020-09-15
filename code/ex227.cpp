class Solution {
public:
    int calculate(string s) {
        s += '+';
        
        stack<char> signs;
        stack<int> nums;
        int temp = 0, sign = 1;
        for (char c : s) {
            if (isdigit(c)) {
                temp = temp * 10 + (c - '0');
            } else if (c != ' ') {
                if (!signs.empty()) {
                    int n1 = nums.top();    nums.pop();
                    if (signs.top() == '*') {
                        nums.push(n1 * temp);
                    } else if (signs.top() == '/') {
                        nums.push(n1 / temp);
                    } else {
                        nums.push(temp * sign);
                    }
                    signs.pop();
                } else {
                    nums.push(temp * sign);    
                }
                temp = 0;
                
                if (c == '-')    sign = -1;
                else if (c == '+')    sign = 1;
                else    signs.push(c);
            }
        }
        
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};