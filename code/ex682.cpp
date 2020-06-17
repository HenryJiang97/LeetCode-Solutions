class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for (string op : ops) {
            if (op == "C") {
                stk.pop();
            } else if (op == "D") {
                stk.push(stk.top() * 2);
            } else if (op == "+") {
                int p1 = stk.top();    stk.pop();
                int p2 = stk.top();
                stk.push(p1);
                stk.push(p1 + p2);
            } else {
                int integer = stoi(op);
                stk.push(integer);
            }
        }
        
        int score = 0;
        while (!stk.empty()) {
            score += stk.top();
            stk.pop();
        }
        
        return score;
    }
};