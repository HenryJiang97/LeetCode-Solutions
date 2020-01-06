class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt = 0;
        unordered_map<char, queue<string>> map;
        for (auto word : words)
            map[word[0]].push(word);
        
        for (int i = 0; i < S.length(); i++) {
            char c = S[i];
            if (map.find(c) != map.end()) {
                queue<string>& que = map[c];
                int size = que.size();
                for (int z = 0; z < size; z++) {
                    string out = que.front();    que.pop();
                    if (out.length() == 1)    cnt++;
                    else    map[out[1]].push(out.substr(1));
                }
            }
        }
        
        return cnt;
    }
};