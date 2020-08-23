struct TrieNode {
    vector<TrieNode*> children;
    bool ifEnd;
    TrieNode() {
        children.resize(26);
        ifEnd = 0;
    }
};


class StreamChecker {
    string s = "";
    TrieNode* root;
    
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (string word : words) {
            TrieNode* p = root;
            for (int i = word.length() - 1; i >= 0; i--) {
                char c = word[i];
                if (p->children[c - 'a'] == NULL)
                    p->children[c - 'a'] = new TrieNode();
                p = p->children[c - 'a'];
            }
            p->ifEnd = 1;
        }
    }
    
    bool query(char letter) {
        s += letter;
        TrieNode* p = root;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (p == NULL || p->children[c - 'a'] == NULL)    return 0;
            p = p->children[c - 'a'];
            if (p->ifEnd)    return 1;
        }
        return 0;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */