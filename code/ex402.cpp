class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        
        stack<char> stk;
        for (char c : num) {
            while (!stk.empty() && stk.top() > c && k > 0) {
                stk.pop();
                k--;
            }
            stk.push(c);
        }
        
        // Remove rest of the k chars from the end
        while (k > 0) {
            stk.pop();
            k--;
        }
        
        // Get result
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        
        // Remove leading zeros
        int start = 0;
        while (start < res.length() && res[start] == '0')    start++;
        
        // Get final answer
        string ret = res.substr(start);
        return ret == "" ? "0" : ret;
    }
};