class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        
        stack<pair<char, int>> stk;    // {char, nums of consecutive chars}
        for (int i = 0; i < n; i++) {
            if (stk.empty() || stk.top().first != s[i])
                stk.push({s[i], 1});
            else if (stk.top().first == s[i]) {
                pair<char, int> out = stk.top();    stk.pop();
                if (out.second + 1 < k) {
                    out.second++;
                    stk.push(out);
                }
            }
        }
        
        // Get result
        string res = "";
        while (!stk.empty()) {
            for (int i = 0; i < stk.top().second; i++)
                res = stk.top().first + res;
            stk.pop();
        }
        
        return res;
    }
};