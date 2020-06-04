class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        // Wrap alphabet characters with {}
        string s = "";
        for (char c : expression) {
            if (isalpha(c)) {
                s = s + '{' + c + '}';
            } else {
                s += c;
            }
        }
        
        // Represents
        stack<unordered_set<string>> stk;
        stack<int> oper;    // 0 -> ',' before, 1 -> '{' before
        unordered_set<string> temp;
        
        for (char c : s) {
            if (c == '{') {
                stk.push(temp);
                temp.clear();
                oper.push(1);
            } else if (c == ',') {
                stk.push(temp);
                temp.clear();
                oper.push(0);
            } else if (c == '}') {
                while (oper.top() == 0) {
                    temp = combine(stk.top(), temp);
                    stk.pop();
                    oper.pop();
                } 
                if (oper.top() == 1) {
                    temp = concat(stk.top(), temp);
                    stk.pop();
                    oper.pop();
                }
            } else {
                string ss = "";
                ss += c;
                temp.insert(ss);
            }
        }
        
        // Get result
        vector<string> res(temp.begin(), temp.end());
        sort(res.begin(), res.end());
        return res;
    }
    
private:
    unordered_set<string> combine(unordered_set<string>& s1, unordered_set<string>& s2) {
        unordered_set<string> res;
        for (string s : s1)    res.insert(s);
        for (string s : s2)    res.insert(s);
        return res;
    }
    
    unordered_set<string> concat(unordered_set<string>& s1, unordered_set<string>& s2) {
        if (s1.size() == 0)    s1.insert("");
        unordered_set<string> res;
        for (string s : s1) {
            for (string t : s2) {
                res.insert(s + t);
            }
        }
        return res;
    }
};