struct TrieNode {
    vector<TrieNode*> children;
    int value;
    TrieNode() {
        value = 0;
        children = vector<TrieNode*>(2);
    }
};

class Solution {
    TrieNode* root = new TrieNode();
public:
    int findMaximumXOR(vector<int>& nums) {
        for (int num : nums)    insert(bitset<32>(num).to_string(), num);
        int MAX = 0;
        for (int num : nums) {
            TrieNode* p = root;
            string number = bitset<32>(num).to_string();
            for (char c : number) {
                if (c == '0') {
                    if (p->children[1] != NULL)    p = p->children[1];
                    else    p = p->children[0];
                } else {
                    if (p->children[0] != NULL)    p = p->children[0];
                    else    p = p->children[1];
                }
            }
            MAX = max(MAX, num ^ p->value);
        }
        return MAX;
    }
    
private:
    // Insert a string
    void insert(string s, int val) {
        TrieNode* p = root;
        for (char c : s) {
            if (p->children[c - '0'] == NULL)
                p->children[c - '0'] = new TrieNode();
            p = p->children[c - '0'];
        }
        p->value = val;
    }
};