class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        
        unordered_set<int> remove;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(')    stk.push(i);
            if (c == ')') {
                if (stk.empty())    remove.insert(i);
                else    stk.pop();
            }
        }
        while (!stk.empty()) {
            remove.insert(stk.top());
            stk.pop();
        }
        
        string res = "";
        for (int i = 0; i < n; i++)
            if (remove.count(i) == 0)    res += s[i];
        return res;
    }
};