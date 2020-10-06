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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)    return new TreeNode(val);
        
        TreeNode* p = root;
        while (1) {
            if (val < p->val) {
                if (p->left == NULL) {
                    p->left = new TreeNode(val);
                    return root;
                }
                p = p->left;
            } else {
                if (p->right == NULL) {
                    p->right = new TreeNode(val);
                    return root;
                }
                p = p->right;
            }
        }
        
        return root;
    }
};