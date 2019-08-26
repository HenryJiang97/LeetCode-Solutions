class Solution {
    unordered_set<string> set;
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.length();
        for (string word : wordList)    set.insert(word);
        if (!contains(endWord))    return 0;
        
        // Run BFS
        queue<string> que;
        que.push(beginWord);
        int transform = 0;
        
        while (!que.empty()) {
            transform++;
            
            for (int z = que.size() - 1; z >= 0; z--) {    // Loop current layer of BFS
                string out = que.front();    que.pop();
                
                for (int d = 0; d < n; d++) {    // Loop each digit in the current string
                    for (int c = 0; c < 26; c++) {
                        if ('a' + c == out[d])    continue;    // Skip the newStr which is the same as old one
                        string newStr = out;    newStr[d] = 'a' + c;
                        if (newStr == endWord)    return transform + 1;
                        if (contains(newStr)) {
                            que.push(newStr);
                            set.erase(newStr);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
    
private:
    bool contains(string s) {
        return set.find(s) != set.end();
    }
};