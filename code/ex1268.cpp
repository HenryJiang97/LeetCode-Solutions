struct Trie {
    // Definition of TrieNode
    struct TrieNode {
        vector<TrieNode*> children;
        bool ifEnd;
        priority_queue<string> strings;
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
            p->strings.push(s);
            if (p->strings.size() > 3)    p->strings.pop();
        }
        p->ifEnd = 1;
    }
    
    // Search for a string
    priority_queue<string> search(string s) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)    return {};
            p = p->children[c - 'a'];
        }
        return p->strings;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for (string product : products)    trie->insert(product);
        
        vector<vector<string>> res;
        string cur = "";
        for (char c : searchWord) {
            cur += c;
            priority_queue<string> results = trie->search(cur);
            vector<string> r;
            while (!results.empty()) {
                r.push_back(results.top());
                results.pop();
            }
            reverse(r.begin(), r.end());
            res.push_back(r);
        }
        
        return res;
    }
};