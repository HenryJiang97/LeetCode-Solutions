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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* v = new TreeNode(val);
        TreeNode* p = root;
        if (p == NULL)    return v;
        if (p->val < val) {
            v->left = root;
            return v;
        } else {
            p->right = insertIntoMaxTree(p->right, val);
        }
        return root;
    }
};