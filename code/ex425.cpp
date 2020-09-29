struct TrieNode {
    vector<TrieNode*> children;
    vector<string> cand;
    TrieNode() {
        children = vector<TrieNode*>(26);
    }
};

class Solution {
    TrieNode* root = new TrieNode();
    int n, l;
    
    void insert(string s) {
        TrieNode* p = root;
        p->cand.push_back(s);
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
            p->cand.push_back(s);
        }
    }
    
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words.size();    l = words[0].size();
        for (string word : words)    insert(word);
        vector<vector<string>> res;
        vector<string> cur;
        unordered_set<string> visited;
        dfs(res, cur, visited);
        return res;
    }
    
private:
    void dfs(vector<vector<string>>& res, vector<string>& cur, unordered_set<string>& visited) {
        if (cur.size() == l) {
            res.push_back(cur);
            return;
        }
        
        TrieNode* p = root;
        for (int i = 0; i < cur.size(); i++) {
            char c = cur[i][cur.size()];
            if (p->children[c - 'a'] == NULL)    return;
            p = p->children[c - 'a'];
        }
        
        for (string nxt : p->cand) {
            cur.push_back(nxt);
            visited.insert(nxt);
            dfs(res, cur, visited);
            cur.pop_back();
            visited.erase(nxt);
        }
    }
};