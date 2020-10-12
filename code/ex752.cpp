class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dict(deadends.begin(), deadends.end());
        
        if (dict.count("0000") > 0)    return -1;
        queue<string> que;
        que.push("0000");
        dict.insert("0000");
        
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                string out = que.front();    que.pop();
                if (out == target)    return step;
                for (int i = 0; i < 4; i++) {
                    string bkp = out;
                    // Add 1
                    if (bkp[i] == '9')    bkp[i] = '0';
                    else    bkp[i]++;
                    if (dict.count(bkp) == 0) {
                        que.push(bkp);
                        dict.insert(bkp);
                    }
                    
                    // Minus 1
                    bkp = out;
                    if (bkp[i] == '0')    bkp[i] = '9';
                    else    bkp[i]--;
                    if (dict.count(bkp) == 0) {
                        que.push(bkp);
                        dict.insert(bkp);
                    }
                }
            }
            step++;
        }
        
        return -1;
    }
};