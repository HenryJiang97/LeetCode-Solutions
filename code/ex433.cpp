const char gene[4] = {'A', 'C', 'G', 'T'};

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (dict.find(end) == dict.end())    return -1;
        
        queue<string> que;
        que.push(start);
        int step = 0;
        
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                string out = que.front();    que.pop();
                for (int i = 0; i < out.length(); i++) {
                    char c = out[i];
                    for (int d = 0; d < 4; d++) {
                        out[i] = gene[d];
                        if (dict.find(out) == dict.end())    continue;
                        if (out == end)    return step + 1;
                        que.push(out);
                        dict.erase(out);
                    }
                    out[i] = c;
                }
            }
            step++;
        }
        
        return -1;
    }
};