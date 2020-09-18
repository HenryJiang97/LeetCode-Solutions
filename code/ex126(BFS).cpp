class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        
        queue<vector<string>> que;
        que.push({beginWord});
        
        while (!que.empty()) {
            int size = que.size();
            unordered_set<string> visited;
            for (int z = size; z > 0; z--) {
                vector<string> out = que.front();    que.pop();
                if (!res.empty() && res.back().size() < out.size())    break;    // Longer than existing results
                if (out.back() == endWord)    res.push_back(out);
                vector<string> nxts = getNextStr(dict, out.back());
                for (string nxt : nxts) {
                    out.push_back(nxt);
                    que.push(out);
                    out.pop_back();
                    visited.insert(nxt);
                }
            }
            for (string v : visited)
                dict.erase(v);
        }
        
        return res;
    }
    
private:
    vector<string> getNextStr(unordered_set<string>& dict, string cur) {
        vector<string> res;
        for (int i = 0; i < cur.length(); i++) {
            char d = cur[i];
            for (char c = 'a'; c <= 'z'; c++) {
                cur[i] = c;
                if (c != d && dict.count(cur) > 0)    res.push_back(cur);
            }
            cur[i] = d;
        }
        return res;
    }
};