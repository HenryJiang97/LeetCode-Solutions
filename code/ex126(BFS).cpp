class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())    return {};
        queue<vector<string>> que;
        que.push({beginWord});
        
        bool found = 0;
        while (!que.empty()) {
            int size = que.size();
            unordered_set<string> visited;
            for (int z = size; z > 0; z--) {
                vector<string> out = que.front();    que.pop();
                string curr = out.back();
                vector<string> next = getNext(curr, dict);
                for (string nxt : next) {
                    if (nxt == endWord) {
                        found = 1;
                        out.push_back(nxt);
                        res.push_back(out);
                        out.pop_back();
                    }
                    out.push_back(nxt);
                    que.push(out);
                    out.pop_back();
                    visited.insert(nxt);
                }
            }
            if (found)    break;
            for (auto v : visited)
                dict.erase(v);
        }
        
        return res;
    }
    
private:
    vector<string> getNext(string str, unordered_set<string>& dict) {
        vector<string> res;
        for (int d = 0; d < str.size(); d++) {
            for (int i = 0; i < 26; i++) {
                string newStr = str;
                newStr[d] = (char)('a' + i);
                if (newStr == str || (dict.find(newStr) == dict.end()))    continue;
                res.push_back(newStr);
            }
        }
        return res;
    }
};