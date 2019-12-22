// DFS

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
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode* root, int bi) {
        bi = (bi << 1) + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += bi;
            return;
        }
        if (root->left != NULL)    dfs(root->left, bi);
        if (root->right != NULL)    dfs(root->right, bi);
    }
};