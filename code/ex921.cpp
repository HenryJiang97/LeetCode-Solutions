class Solution {
public:
    int minAddToMakeValid(string S) {
        int cnt = 0;
        stack<char> stk;
        for (char c : S) {
            if (c == '(') {
                stk.push(c);
            } else {    // ')'
                if (stk.empty())    cnt++;
                else    stk.pop();
            }
        }
        return cnt + stk.size();
    }
};