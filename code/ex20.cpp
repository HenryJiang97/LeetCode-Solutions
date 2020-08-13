class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map{{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> stk;
        for (char c : s) {
            if (map.count(c) == 0) {
                stk.push(c);
            } else {
                if (stk.empty() || stk.top() != map[c])    return 0;
                stk.pop();
            }
        }
        return stk.empty();
    }
};