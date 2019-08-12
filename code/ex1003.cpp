// Stack

class Solution {
public:
    bool isValid(string S) {
        int n = S.length();
        
        stack<char> stk;
        for (int i = 0; i < n; i++) {
            if (S[i] == 'c') {
                if (stk.size() < 2)    return false;
                char p1 = stk.top();    stk.pop();
                char p2 = stk.top();    stk.pop();
                if (!(p1 == 'b' && p2 == 'a'))    return false;
            } else {
                stk.push(S[i]);
            }
        }
        
        return stk.empty();
    }
};