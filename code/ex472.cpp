struct Trie {
    // Definition of TrieNode
    struct TrieNode {
        vector<TrieNode*> children;
        bool ifEnd;
        TrieNode() {
            children = vector<TrieNode*>(26);
            ifEnd = 0;
        }
    };

    //////////////////////////////////////////////////////////
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a string
    void insert(string s) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->ifEnd = 1;
    }
    
    // Search for a string
    bool search(string s) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)    return 0;
            p = p->children[c - 'a'];
        }
        return p->ifEnd;
    }
};


class Solution {
    Trie* trie = new Trie();
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (string word : words)    trie->insert(word);
        
        vector<string> res;
        unordered_map<string, bool> memo;
        for (string word : words) {
            int n = word.length();
            for (int i = 1; i <= n - 1; i++) {
                string first = word.substr(0, i), second = word.substr(i);
                if (trie->search(first) && backtracking(second, memo)) {
                    res.push_back(word);
                    break;
                }
            }
        }
        
        return res;
    }
    
private:
    bool backtracking(string word, unordered_map<string, bool>& memo) {
        if (word.length() == 0)    return 1;
        if (memo.count(word) > 0)    return memo[word];
        bool res = 0;
        for (int i = 1; i <= word.length(); i++) {
            string cur = word.substr(0, i), nxt = word.substr(i);
            if (trie->search(cur) && backtracking(nxt, memo)) {
                res = 1;
                break;
            }
        }
        memo[word] = res;
        return res;
    }
};