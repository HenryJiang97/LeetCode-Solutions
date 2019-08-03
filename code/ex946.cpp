// Stack

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        
        stack<int> stk;
        int p1 = 0, p2 = 0;
        while (p2 < n) {
            if (p1 >= n && stk.top() != popped[p2])    return false;
            
            while (stk.empty() || stk.top() != popped[p2]) {
                stk.push(pushed[p1++]);
                if (p1 >= n && stk.top() != popped[p2])    return false;
            }

            stk.pop();    p2++;
        }
        
        return true;
    }
};