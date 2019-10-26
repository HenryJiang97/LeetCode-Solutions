// Prefix

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int res = 0;
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)    return 0;
        unordered_map<int, int> m;    m.insert({0, 1});
        dfs(root, sum, 0, m);
        return res;
    }
    
private:
    void dfs(TreeNode* root, int sum, int s, unordered_map<int, int>& m) {
        if (root == NULL)    return;
        s += root->val;
        if (m.find(s - sum) != m.end())    res += m[s - sum];
        m[s]++;    // Add to prefix map
        
        dfs(root->left, sum, s, m);
        dfs(root->right, sum, s, m);
        
        if(--m[s] == 0)    m.erase(s);    // Remove from prefix map
    }
};