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
public:
    void recursion(TreeNode* root) {
        // Backup left and right child node
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        // Swap left and right child node
        root->left = r;
        root->right = l;

        // Continue to recursion
        if (root->left != NULL)
            recursion(root->left);
        if (root->right != NULL)
            recursion(root->right);

    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;

        recursion(root);

        return root;
    }
};