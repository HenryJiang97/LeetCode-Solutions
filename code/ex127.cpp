class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.count(endWord) == 0)    return 0;
        
        queue<string> que;
        que.push(beginWord);
        
        int step = 0;
        while (!que.empty()) {
            int size = que.size();
            while (size--) {
                string out = que.front();    que.pop();
                if (out == endWord)    return step + 1;
                for (int i = 0; i < out.length(); i++) {
                    char c = out[i];
                    for (char nc = 'a'; nc <= 'z'; nc++) {
                        out[i] = nc;
                        if (dict.count(out) > 0) {
                            dict.erase(out);
                            que.push(out);
                        }
                    }
                    out[i] = c;
                }
            }
            step++;
        }
        
        return 0;
    }
};