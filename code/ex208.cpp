struct TrieNode {
    bool ifEnd = false;
    TrieNode* children[26] = {nullptr};
    TrieNode () {}
};

class Trie {
    TrieNode* root = new TrieNode();
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (p->children[c - 'a'] == NULL) {
                p->children[c - 'a'] = new TrieNode();
            }
            p = p->children[c - 'a'];
        }
        p->ifEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* end = navigate(word);
        return end != NULL && end->ifEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return navigate(prefix) != NULL;
    }
    
    TrieNode* navigate(string s) {    // Navigate to the end node of the string
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)    return NULL;
            p = p->children[c - 'a'];
        }
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */