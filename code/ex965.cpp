/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool verify(TreeNode* root, int val) {
        if (root == NULL)    return 1;
        if (root->val != val)    return 0;
        return verify(root->left, val) && verify(root->right, val);
    }
    
public:
    bool isUnivalTree(TreeNode* root) {
        return verify(root, root->val);
    }
};