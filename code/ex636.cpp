class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> functions;    // Save ids of the functions
        stack<int> lastTime;    // Save last beginning or ending time
        vector<int> res = vector<int>(n);
        
        for (int i = 0; i < logs.size(); i++) {
            auto p = split(logs[i]);
            int id = p[0], time = p[1], state = p[2];
            
            if (!functions.empty()) {
                if (state == 0) {    // Start point
                    res[functions.top()] += (time - lastTime.top());
                    functions.pop();
                    lastTime.pop();
                    lastTime.push(time);
                } else {    // End point
                    res[functions.top()] += (time - lastTime.top() - 1);
                    functions.push(id);
                    lastTime.pop();
                    lastTime.push(time - 1);
                }
            } else {    // Start of a new interval
                lastTime.push(time - 1);
                functions.push(id);
            }
        }
        
        return res;
    }
    
private:
    vector<int> split(string s) {
        int id = 0, time = 0;
        int lo = 0, hi = s.length() - 1;
        while (s[lo] != ':')    lo++;
        while (s[hi] != ':')    hi--;
        
        id = stoi(s.substr(0, lo));
        time = stoi(s.substr(hi + 1));
        
        int state = s.substr(lo + 1, hi - lo - 1) == "start" ? 1 : 0;
        
        return {id, time, state};
    }
};