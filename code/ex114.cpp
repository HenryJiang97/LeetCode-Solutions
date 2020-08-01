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
    void flatten(TreeNode* root) {
        TreeNode* p = root;
        while (p != NULL) {
            if (p->left != NULL) {
                TreeNode* rightBKP = p->right;
                p->right = p->left;    p->left = NULL;
                
                // Find the end of left subtree
                TreeNode* end = p->right;
                while (end->right != NULL)    end = end->right;
                
                end->right = rightBKP;
            }
            p = p->right;
        }
    }
};