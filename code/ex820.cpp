struct TrieNode {
    TrieNode* children[26] = {nullptr};
};

struct cmp {
    bool operator()(string s1, string s2) {
        return s2.length() < s1.length();
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp());
        TrieNode* root = new TrieNode();
        int len = 0;
        for (string word : words) {
            TrieNode* p = root;
            for (int i = word.length() - 1; i >= 0; --i) {
                char c = word[i];
                if (p->children[c - 'a'] == NULL) {
                    if (i == 0)    len += word.length() + 1;
                    p->children[c - 'a'] = new TrieNode();
                }
                p = p->children[c - 'a'];
            }
        }
        return len;
    }
};