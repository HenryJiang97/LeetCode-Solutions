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
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
    
private:
    void dfs (TreeNode*& root) {
        if (root == NULL)    return;
        dfs(root->right);
        sum += root->val;
        root->val = sum;
        dfs(root->left);
    }
};