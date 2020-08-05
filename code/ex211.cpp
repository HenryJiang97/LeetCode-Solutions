class WordDictionary {
    struct TrieNode {
        vector<TrieNode*> children;
        bool ifEnd = 0;
        TrieNode() {
            children = vector<TrieNode*>(26);
        }
    };
    
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (p->children[c - 'a'] == NULL)
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->ifEnd = 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        return helper(word, 0, root);
    }
    
    bool helper(string word, int s, TrieNode* p) {
        if (s >= word.length())    return p != NULL && p->ifEnd;
        for (int i = s; i < word.length(); i++) {
            char c = word[i];
            if (c != '.') {
                if (p == NULL)    return 0;
                if (p->children[c - 'a'] == NULL)    return 0;
                p = p->children[c - 'a'];
                if (i == word.size() - 1)    return p->ifEnd;
            } else {
                for (int j = 0; j < 26; j++) {
                    if (p->children[j] == NULL)    continue;
                    if (helper(word, i + 1, p->children[j]))    return 1;
                }
                return 0;
            }
        }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */