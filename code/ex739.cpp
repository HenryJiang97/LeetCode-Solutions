// Monotone stack

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n);
        
        stack<pair<int, int>> stk;    // {val, temp}
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top().first < T[i]) {
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({T[i], i});
        }
        
        return res;
    }
};