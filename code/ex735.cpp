// Stack

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n =  asteroids.size();
        
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top() > 0 && asteroids[i] < 0 && stk.top() < -asteroids[i]) {
                stk.pop();
            }
            // When two asteroids have same size
            if (!stk.empty() && stk.top() > 0 && stk.top() == -asteroids[i]) {
                stk.pop();    continue;
            }
            // When stk.top() has the same sign with asteroids[i], push asteroids into the stack
            if (stk.empty() || stk.top() * asteroids[i] > 0 || stk.top() < 0)    stk.push(asteroids[i]);
        }
        
        // Get result
        vector<int> res(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--) {
            res[i] = stk.top();    stk.pop();
        }
        
        return res;
    }
};