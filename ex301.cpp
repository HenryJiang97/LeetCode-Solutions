class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        
        // Get number of open brackets and close brackets in the string
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(')    open++;
            else if (c == ')') {
                if (open > 0)    open--;
                else    close++;
            }
        }
        
        // Get the result
        vector<string> res;
        backtracking(s, 0, open, close, res);
        
        return res;
    }
    
private:
    void backtracking(string s, int start, int open, int close, vector<string>& res) {
        if (open == 0 && close == 0) {
            if (ifValid(s))    res.push_back(s);
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            if (i != start && s[i] == s[i - 1])    continue;
            if (s[i] == '(') {
                backtracking(s.substr(0, i) + s.substr(i + 1) , i, open - 1, close, res);
            } else if (s[i] == ')') {
                backtracking(s.substr(0, i) + s.substr(i + 1) , i, open, close - 1, res);
            }
        }
    }
    
    bool ifValid(string s) {
        int open = 0;
        
        for (char c : s) {
            if (c == '(')    open++;
            else if (c == ')')    open--;
            if (open < 0)    return false;
        }
        
        return open == 0;
    }
};