class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        queue<string> que;
        que.push(beginWord);
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int z = size; z > 0; z--) {
                string out = que.front();    que.pop();
                if (out == endWord)    return step + 1;
                vector<string> nxts = getNexts(dict, out);
                for (string nxt : nxts) {
                    que.push(nxt);
                    dict.erase(nxt);
                }
            }
            step++;
        }
        
        return 0;
    }
    
private:
    vector<string> getNexts(unordered_set<string>& dict, string cur) {
        vector<string> res;
        for (int i = 0; i < cur.length(); i++) {
            char d = cur[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == d)    continue;
                cur[i] = c;
                if (dict.count(cur) > 0)    res.push_back(cur);
            }
            cur[i] = d;
        }
        return res;
    }
};