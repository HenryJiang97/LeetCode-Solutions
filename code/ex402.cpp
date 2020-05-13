class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        
        stack<char> stk;
        int i = 0;
        for ( ; i < n; i++) {
            while (!stk.empty() && stk.top() > num[i]) {
                stk.pop();
                if (--k == 0)    break;
            }
            if (k == 0)    break;
            if (stk.empty() && num[i] == '0')    continue;
            stk.push(num[i]);
        }
        
        // Remove extra chars
        while (k > 0) {
            if (!stk.empty())    stk.pop();
            else    i++;
            k--;
        }
            
        // Build new string
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        while (i < n && res == "" && num[i] == '0')    i++;    // Remove redundant prefix zeros
        if (i < n)    res += num.substr(i);    // Add rest of the string
        
        return res == "" ? "0" : res;
    }
};