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
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)    return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if (root->left == NULL)    root = right;
            else {
                root = left;
                TreeNode* lr = left->right;
                if (right == NULL)    root->right = lr;
                else {
                    left->right = right;
                    if (lr != NULL) {
                        TreeNode* p = right;
                        while (p->left != NULL)    p = p->left;
                        p->left = lr;
                    }
                }
            }
        }
        return root;
    }
};