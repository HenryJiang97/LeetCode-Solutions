class Solution {
public:
    string solveEquation(string equation) {
        vector<string> part = split(equation);
        vector<int> left = decode(part[0]);
        vector<int> right = decode(part[1]);
        int lx = left[0], lval = left[1], rx = right[0], rval = right[1];
        
        if (lx == rx && lval != rval)    return "No solution";
        if (lx == rx)    return "Infinite solutions";
        
        int x = lx - rx, val = rval - lval;
        return "x=" + to_string(val / x);
    }
    
private:
    vector<string> split(string s) {
		s += '=';
        vector<string> res;
        string temp = "";
        for (char c : s) {
            if (c == '=') {
                res.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        return res;
    }
    
    vector<int> decode(string e) {
        e += '+';
        int x = 0, val = 0, num = INT_MIN, sign = 1;
        bool isCoeff = 0;    // If the number is the coefficient
        
        for (char c : e) {
            if (c == '+' || c == '-') {
                if (num != INT_MIN) {
                    if (isCoeff)    x += sign * num;
                    else    val += sign * num;
                }
                isCoeff = 0;
                num = INT_MIN;
                sign = c == '+' ? 1 : -1;
            } else if (c == 'x') {
                isCoeff = 1;
                if (num == INT_MIN)    num = 1;
            } else {
                if (num == INT_MIN)    num = 0;
                num = num * 10 + (c - '0');
            }
        }
        
        return {x, val};
    }
};