#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> ii;

const int mod = 1e9 + 7;
const int dir2[2][2] = {{-1, 0}, {0, -1}};
const int dir4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// cmp
struct cmp {
    bool operator()(int a, int b) {
        return b < a;
    }
};

// trie
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