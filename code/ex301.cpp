class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        
        int open = 0, close = 0;
        for (char c : s) {
            if (c == '(')    open++;
            else if (c == ')') {
                if (open > 0)    open--;
                else    close++;
            }
        }
        
        vector<string> res;
        backtracking(s, res, open, close, 0);
        
        return res;
    }
    
private:
    void backtracking(string s, vector<string>& res, int open, int close, int start) {
        if (open == 0 && close == 0) {
            if (ifValid(s))    res.push_back(s);
            return;
        }
        
        for (int i = start; i < s.length(); i++) {
            // Skip duplicates
            if (i != start && s[i] == s[i - 1])    continue;
            
            // Pick a char to delete
            if (s[i] == '(')    backtracking(s.substr(0, i) + s.substr(i + 1), res, open - 1, close, i);
            if (s[i] == ')')    backtracking(s.substr(0, i) + s.substr(i + 1), res, open, close - 1, i);
        }
    }
    
    bool ifValid(string s) {
        int open = 0;
        for (char c : s) {
            if (c == '(')    open++;
            else if (c == ')') {
                if (--open < 0)    return false;
            }
        }
        return open == 0;
    }
};