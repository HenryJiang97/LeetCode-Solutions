// Monotonous stack

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();    if (n == 0)    return "";
        
        // Store the last index of each distince character
        vector<int> last_idx(26);
        for (int i = 0; i < n; i++)    last_idx[s[i] - 'a'] = i;
        
        // Use a monotonous stack to store the result
        stack<char> stk;    stk.push(s[0]);
        unordered_set<char> set;    set.insert(s[0]);
        
        for (int i = 1; i < n; i++) {
            if (set.find(s[i]) != set.end())    continue;
            
            while (!stk.empty() && stk.top() >= s[i] && last_idx[stk.top() - 'a'] >= i) {
                set.erase(stk.top());
                stk.pop();
            }
            
            stk.push(s[i]);
            set.insert(s[i]);
        }
        
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        
        return res;
    }
};