struct TrieNode {
    vector<TrieNode*> children;
    bool ifEnd;
    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
        ifEnd = 0;
    }
};

class Solution {
    const int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    TrieNode* root = new TrieNode();
    unordered_set<string> res;
    int m, n;
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();    if (m == 0)    return {};
        n = board[0].size();    if (n == 0)    return {};
        
        for (string word : words)    insert(word);    // Add each word in the wordlist to Trie Tree
        
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                if (root->children[c - 'a'] == NULL)    continue;
                string cur = "";
                visited[i][j] = 1;
                dfs(board, i, j, root->children[c - 'a'], cur + c, visited);
                visited[i][j] = 0;
            }
        }
        
        vector<string> r(res.begin(), res.end());
        return r;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode*& node, string cur, vector<vector<bool>>& visited) {
        if (node->ifEnd)    res.insert(cur);
        
        for (auto& d : dir) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || nj < 0 || ni >= m || nj >= n || visited[ni][nj])    continue;
            
            char c = board[ni][nj];
            TrieNode* nextNode = node->children[c - 'a'];
            if (nextNode == NULL)    continue;
            visited[ni][nj] = 1;
            dfs(board, ni, nj, nextNode, cur + c, visited);
            visited[ni][nj] = 0;
        }
    }
    
private:
    void insert(string s) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - 'a'] == NULL)
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
        }
        p->ifEnd = 1;
    }
};