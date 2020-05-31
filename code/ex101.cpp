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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)    return 1;
        return helper(root->left, root->right);
    }
    
private:
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL)
            return left == NULL && right == NULL;
        
        if (left->val != right->val)    return 0;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};