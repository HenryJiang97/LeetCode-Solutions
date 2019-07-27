// Monotone stack

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();    if (n == 0)    return "";
        
        // Store the last index of each distince character
        vector<int> last_idx(26);
        for (int i = 0; i < n; i++)    last_idx[s[i] - 'a'] = i;
        
        // Use a monotone stack to store the result
        stack<char> stk;    stk.push(s[0]);
        unordered_set<char> set;    set.insert(s[0]);    // Keep track of if this char appeared before
        
        for (int i = 1; i < n; i++) {
            if (set.find(s[i]) != set.end())    continue;    // Skip this char if it already existed before
            
            // Remove chars before i which are lexicographically larger than s[i] to keep monotony of the stack
            while (!stk.empty() && stk.top() >= s[i] && last_idx[stk.top() - 'a'] >= i) {
                set.erase(stk.top());
                stk.pop();
            }
            
            stk.push(s[i]);
            set.insert(s[i]);
        }
        
        // Save to result
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        
        return res;
    }
};